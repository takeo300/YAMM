#include "skype.h"

bool SkypesendCommand(char* InputCommand)
{
        if( hWndskype!=NULL )
        {
            COPYDATASTRUCT CopyData;


            CopyData.dwData=0;
            CopyData.lpData=InputCommand;
            cout<<"Output: "<<InputCommand<<endl;
            CopyData.cbData=strlen(InputCommand)+1;
            if( CopyData.cbData!=1 )
            {
                 if(SendMessage( hWndskype, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&CopyData)==1)
                 {


                   printf("Gesendet!\n");
                   return true;
                 }
                 return false;

            }
        }
        return false;
}

bool SkypesendAttach(HWND WindowHandle)
{
    if(SendMessage( HWND_BROADCAST, WM_SkypeControlAPIDiscover, (WPARAM)WindowHandle, (LPARAM)WindowHandle)==1)
    {
        return true;
    }
    return false;
}


bool SkypeInit(void)
{
    WM_SkypeControlAPIDiscover  =  RegisterWindowMessage("SkypeControlAPIDiscover");
    WM_SkypeControlAPIAttach    = RegisterWindowMessage("SkypeControlAPIAttach");
            if (WM_SkypeControlAPIDiscover == 0)
        {
            MessageBox(0, "Window Message \"SkypeControlAPIDiscover\" konnte nicht registriert werden  ", "Fehler", MB_OK | MB_ICONSTOP );
            return 1;
        }

        if (WM_SkypeControlAPIAttach == 0)
        {
            MessageBox(0, "Window Message \"SkypeControlAPIAttach\" konnte nicht registriert werden  ", "Fehler", MB_OK | MB_ICONSTOP);
            return 1;
        }
    return 0;
}

int SkypecheckAPIAttach(HWND WindowHandle, UINT msg, WPARAM wParam, LPARAM lParam)
{
 if( msg==WM_SkypeControlAPIAttach )
        {
            switch(lParam)
            {
            case SKYPECONTROLAPI_ATTACH_SUCCESS:
                printf("!!! Connected\n");
                hWndskype=(HWND)wParam;
                return 0;
                break;
            case SKYPECONTROLAPI_ATTACH_PENDING_AUTHORIZATION:
                printf("!!! Pending authorization\n");
                return 1;
                break;
            case SKYPECONTROLAPI_ATTACH_REFUSED:
                printf("!!! Connection refused\n");
                return 2;
                break;
            case SKYPECONTROLAPI_ATTACH_NOT_AVAILABLE:
                printf("!!! Skype API not available\n");
                return 3;
                break;
            case SKYPECONTROLAPI_ATTACH_API_AVAILABLE:
                printf("!!! Try connect now (API available); issue #connect\n");
                SkypesendAttach(WindowHandle);
                break;
            }


        }

return 4;
}

int SkypeCreateCall(string target1,...)
{
    char* cstr[target1.size()+5];
    cstr=(char*)"CALL";
    // strcpy(cstr,"CALL");

    strcpy (cstr, target1.c_str());

    if(SkypesendCommand(cstr)==true)
    {
        return 0;
    }
    return 1;
}
