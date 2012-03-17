#include "main.h"
#ifdef windows
#include <windows.h>
#endif

// DLL-Code here

bool init(std::string username, std::string password, void (*error)(std::string msg), void (*receiveMessage)(std::string user, std::string msg))
{
    #ifdef windows

    #endif
    return false;
}

#ifdef windows
int CALLBACK WinMain(
  __in  HINSTANCE hInstance,
  __in  HINSTANCE hPrevInstance,
  __in  LPSTR lpCmdLine,
  __in  int nCmdShow
)
{
    return 0;
}
#else
int main()
{
    return 0;
}
#endif
