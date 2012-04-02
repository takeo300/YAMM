// custom includes
#include "main.h"

using namespace std;

// DLL-Code here

/// TODO: edlere Lösung => main.cpp soll durch include entweder main_linux oder main_windows einbinden: größere Lesbarkeit
HWND messageThreadWindowHandle = 0;
HWND messageThreadHandle = 0;
HWND skypeHandle = 0;

UINT WM_SkypeControlAPIDiscover   =  0 ;
UINT WM_SkypeControlAPIAttach     =  0 ;
// Anwendungsfenster erzeugen
HWND CreateMainWindow(HINSTANCE hInstance);

// Callback Funktion zur Nachrichtenbehandlung
LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

bool skypeReady = false;
#ifdef _WIN32
void sendCommand(string command)
{
    YAMM::CopyDataStruct* cmd  = new YAMM::CopyDataStruct;

    cmd->ID = "1";
    cmd->Data = command;
    cmd->Length = command.size()+1;

    PDWORD_PTR result;

    // message pump thread must receive the messages, that's why messageThreadWindowHandle instead of DLL-handle
    SendMessageTimeout(skypeHandle, WM_COPYDATA, WPARAM(messageThreadWindowHandle), LPARAM(cmd), SMTO_NORMAL, 100, result);
}

/** message handler for the DLL's message loop. Will be called in a other thread than the DLL's main thread.
  * @see messageLoop
  */
LRESULT CALLBACK MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_COPYDATA:
            MessageBox(0, "WM_COPYDATA empfangen!" , "Erfolg!", MB_OK|MB_ICONINFORMATION);
        break;
        case WM_LBUTTONDOWN:
            PostMessage(HWND_BROADCAST, WM_SkypeControlAPIDiscover ,(WPARAM) hWnd,NULL);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        break;
        //case 0xC218:

        //break;

    }
    if (msg== WM_SkypeControlAPIAttach)
    {
        MessageBox(0, "Skype hat geantwortet" , "Erfolg!", MB_OK|MB_ICONINFORMATION);
        skypeReady = lParam == 0;
        if(lParam == 1)
        {
            MessageBox(0, "Benötige Berechtigung" , "Erfolg!", MB_OK|MB_ICONINFORMATION);
        }
    }
    else{
    return DefWindowProc(hWnd,msg,wParam,lParam);
    }
}

void messageLoop(HINSTANCE hndl)
{
    messageThreadWindowHandle = CreateMainWindow(hndl);
    if(0 == messageThreadWindowHandle)
    {
        MessageBox(0, "Nachrichtenfenster konnte nicht erzeugt werden", "Fehler", MB_OK);
        return;// false;
    }
    // Struktur, in der Informationen zur Nachricht gespeichert werden
    MSG msg;
    // message loop must use a seperate thread: it must not block the initialization function
    while(GetMessage(&msg, NULL, 0, 0))
	{
        // Nachricht an die Callbackfunktion senden
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

}

bool init(HINSTANCE hinstDLL,DWORD fdwReason, LPVOID lpvReserved)
{
    DWORD* threadId;
    LPVOID
    messageThreadHandle = CreateThread (NULL, 0, messageLoop, &((HINSTANCE)messageThreadWindowHandle), 0, threadId);

     // Fenster erzeugen und Handle speichern


    // Wenn der Rueckgabewert 0 ist, ist ein Fehler aufgetreten
    if(0 == messageThreadWindowHandle)
    {
        MessageBox(0, "Nachrichtenschleife konnte nicht erzeugt werden", "Fehler", MB_OK);
        return false;
    }

    // idea: we retrieve the "ports" that skype is listening at. The first call to RegisterWindowMessage assigns the message's name to an unique integer, the subsequent ones don't actually register them but retrieve the values.
    WM_SkypeControlAPIDiscover =  RegisterWindowMessage("SkypeControlAPIDiscover");
    WM_SkypeControlAPIAttach = RegisterWindowMessage("SkypeControlAPIAttach");

    if (WM_SkypeControlAPIDiscover == 0)
    {
        MessageBox(0, "Window Message \"SkypeControlAPIDiscover\" konnte nicht registriert werden  ", "Fehler", MB_OK | MB_ICONSTOP );
    }
    if (WM_SkypeControlAPIAttach == 0)
    {
        MessageBox(0, "Window Message \"SkypeControlAPIAttach\" konnte nicht registriert werden  ", "Fehler", MB_OK | MB_ICONSTOP);
    }

    // Diese Schleife läuft bis die Nachricht WM_QUIT empfangen wird
    // Rueckgabewert an Windows
    return 0;
}

bool YAMM::finalize()
{
    // wait for thread to end
    SendMessage(messageThreadWindowHandle, WM_QUIT, 0, 0);
    // release the handle, thread context becomes invalid.
    CloseHandle (messageThreadWindowHandle);
    MessageThreadWindowHandle = 0;
    return true;
}

HWND CreateMainWindow(HINSTANCE hInstance)
{
    WNDCLASSEX wndClass =
    {
        sizeof(WNDCLASSEX),                                 // Groesse angeben
        CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW,    // Standardstile
        MessageHandler,                                     // Callback-Funktion
        0,                                                  // Zusaetzliche Angaben
        0,                                                  // nicht benoetigt
        hInstance,                                          // Anwendungsinstanz
        LoadIcon(NULL, IDI_WINLOGO),                        // Windows-Logo
        LoadCursor(NULL, IDC_ARROW),                        // Normaler Cursor
        (HBRUSH)GetStockObject(WHITE_BRUSH),                // Weisser Pinsel
        NULL,                                               // kein Menue
        "WindowClass",                                      // Der Name der Klasse
        LoadIcon(NULL, IDI_WINLOGO)                         // Windows Logo
    };


    RegisterClassEx(&wndClass);

    return CreateWindowEx(NULL,                   // Keine erweiterten Stile nutzen
                          "WindowClass",          // Klassenname
                          "Hello Windows",        // Fenstertitel
                          WS_OVERLAPPEDWINDOW |   // Fenster
                          WS_VISIBLE,             // Eigenschaften
                          100, 100, 400, 300,     // Anfangsposition und Groesse
                          NULL,                   // Handle des Elternfensters
                          NULL,                   // Handle des Menues
                          hInstance,              // Anwendungsinstanz
                          NULL);                  // wird nicht benoetigt
}

#endif


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
  DWORD fdwReason,
  LPVOID lpvReserved
)
{
    switch(fdwReason)
    {
    case DLL_PROCESS_ATTACH :
        return YAMM::init(hinstDLL, fdwReason, lpvReserved);
    case DLL_PROCESS_DETACH:
        return YAMM::finalize();
    }
}


