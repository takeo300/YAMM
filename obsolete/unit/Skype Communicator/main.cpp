#include <windows.h>
#include "skype.h"
#include <iostream>
// Anwendungsfenster erzeugen
HWND CreateMainWindow(HINSTANCE hInstance);

// Callback Funktion zur Nachrichtenbehandlung
LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    Logger::showDebugMessages(true);
    if (!Skype::init(CreateMainWindow(hInstance))) {
        Logger::log("Initialization failed", Logger::TYPE_URGENT);
        return -1;
    }
    
    
    
  
      MSG msg;
    // Diese Schleife läuft bis die Nachricht WM_QUIT empfangen wird
    while(GetMessage(&msg, NULL, 0, 0))
    {
        // Nachricht an die Callbackfunktion senden
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
     


    // Rueckgabewert an Windows
    return 0;

}






LRESULT CALLBACK MessageHandler(HWND hWnd, 
        UINT msg, 
        WPARAM wParam, 
        LPARAM lParam) {
    
    switch(msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        case WM_COPYDATA:
            Skype::handleMessage(msg, wParam, lParam);
            break;
            
        case WM_LBUTTONDOWN:
            Skype::call();
            break;
            
        default:
            Skype::checkApiAttach(msg, wParam, lParam);
            return DefWindowProc(hWnd,msg,wParam,lParam);
    }
    
    
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
