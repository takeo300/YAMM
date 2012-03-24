#include "skype.h"

bool SkypesendCommand(char* InputCommand)
{
        if( hWndskype!=NULL )
        {
            COPYDATASTRUCT CopyData;


            CopyData.dwData=0;
            CopyData.lpData=InputCommand;
            CopyData.cbData=strlen(InputCommand)+1;
            if( CopyData.cbData!=1 )
            {
                 SendMessage( hWndskype, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&CopyData);
                   printf("Gesendet!\n");

            }
        }
}
