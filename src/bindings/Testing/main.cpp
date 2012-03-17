#include <windows.h>
#include <iostream>

// Anwendungsfenster erzeugen
HWND CreateMainWindow(HINSTANCE hInstance);

// Callback Funktion zur Nachrichtenbehandlung
LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


// Das Fensterhandle
HWND hWnd = 0;
HWND hWndskype = 0;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Fenster erzeugen und Handle speichern
    hWnd = CreateMainWindow(hInstance);
    hWndskype = FindWindow("tSkMainForm",NULL);
    // Wenn der Rueckgabewert 0 ist, ist ein Fehler aufgetreten
    if(0 == hWnd)
    {
        MessageBox(0, "Fenster konnte nicht erzeugt werden", "Fehler", MB_OK);
        return 0;
    }
    if(0 == hWndskype)
    {
        MessageBox(0, "Skype Handle nicht gefunden", "Fehler", MB_OK);
        return 0;
    }

	// Struktur, in der Informationen zur Nachricht gespeichert werden
    MSG msg;

    RegisterWindowMessage("SkypeControlAPIDiscover");
    RegisterWindowMessage("SkypeControlAPIAttach");
    // Diese Schleife laeuft bis die Nachricht WM_QUIT empfangen wird
    while(GetMessage(&msg, NULL, 0, 0))
	{
        // Nachricht an die Callbackfunktion senden
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Rueckgabewert an Windows
    return 0;

}

LRESULT CALLBACK MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_COPYDATA:
        std::cout<<"out";
        break;
        case WM_LBUTTONDOWN:
        PostMessage(hWndskype,(UINT) "SkypeControlAPIDiscover",hWnd,lParam);
        std::cout<<"click";
        break;
        case WM_DESTROY:
                    PostQuitMessage(0);
                    return 0;
                break;
    }
    return DefWindowProc(hWnd,msg,wParam,lParam);
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
