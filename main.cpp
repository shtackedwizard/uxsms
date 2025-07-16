#include <windows.h>
#include <dwmapi.h>

#pragma comment(lib, "dwmapi.lib")

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
    DWMNCRENDERINGPOLICY pol = DWMNCRP_DISABLED;
    DwmSetWindowAttribute(hWnd, DWMWA_NCRENDERING_POLICY, &pol, sizeof(pol));
    return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    for (;;) {
        Sleep(50);
        EnumDesktopWindows(NULL, EnumWindowsProc, NULL);
    }
    return 0;
}
