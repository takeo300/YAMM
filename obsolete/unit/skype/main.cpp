#include <windows.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "skype.h"

//define globals
HWND hWndskype = 0;
HWND hWnd = 0;

// Anwendungsfenster erzeugen
HWND CreateMainWindow(HINSTANCE hInstance);

// Callback Funktion zur Nachrichtenbehandlung
LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

using namespace std;
// Das Fensterhandle


UINT WM_SkypeControlAPIDiscover   =  0 ;
UINT WM_SkypeControlAPIAttach     =  0 ;



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    hWnd = CreateMainWindow(hInstance);


    if(0 == hWnd)
    {
        MessageBox(0, "Fenster konnte nicht erzeugt werden", "Fehler", MB_OK);
        return 0;
    }

    MSG msg;

    WM_SkypeControlAPIDiscover  =  RegisterWindowMessage("SkypeControlAPIDiscover");
    WM_SkypeControlAPIAttach    = RegisterWindowMessage("SkypeControlAPIAttach");

    {


        if (WM_SkypeControlAPIDiscover == 0)
        {
            MessageBox(0, "Window Message \"SkypeControlAPIDiscover\" konnte nicht registriert werden  ", "Fehler", MB_OK | MB_ICONSTOP );
        }

        if (WM_SkypeControlAPIAttach == 0)
        {
            MessageBox(0, "Window Message \"SkypeControlAPIAttach\" konnte nicht registriert werden  ", "Fehler", MB_OK | MB_ICONSTOP);
        }
    }


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

LRESULT CALLBACK MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_COPYDATA:

        if (wParam ==(WPARAM) hWndskype)
        {
            char s[5120]= {};
            PCOPYDATASTRUCT pCopyData=(PCOPYDATASTRUCT)lParam;
            sprintf(s, "Answer: %.*s\n",  pCopyData->cbData, pCopyData->lpData);
            printf(s);

            //MessageBox(hWnd, s, "ShowMessageParameters", MB_OK);
        }

        break;
    case WM_RBUTTONDOWN:
        SkypeCreateCall("echo123");
        break;
    case WM_LBUTTONDOWN:
        SkypesendAttach(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        break;
    default:
        SkypecheckAPIAttach(hWnd, msg,  wParam,  lParam);
        return DefWindowProc(hWnd,msg,wParam,lParam);
        break;

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
