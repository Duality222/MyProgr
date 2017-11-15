#include <windows.h>
#include <stdlib.h>
#include <time.h>

bool ParseVKey(int vKey);

int main()
{
    HWND hWnd = GetForegroundWindow();
    HDC hDC = GetDC(hWnd);
    RECT pRect = {0};

    SetTextColor(hDC, RGB(0,255,0));

    srand(time(0));
    long i, j;
    char szText[50][80] = {0};

    bool bWork = true;
    while( bWork )
    {
        ShowWindow(hWnd, SW_RESTORE);
        SetForegroundWindow(hWnd);
        GetClientRect(hWnd, &pRect);

        Rectangle(hDC, 0, 0, pRect.right, pRect.bottom);
        DrawText(hDC, "PRESS ESC - FOR EXIT", 15, &pRect, DT_CENTER);

        for(i = 0; i < 50; i++)
        for(j = 0; j < 80; j++)
            szText[i][j] = (j + 1 < 80 ? '0' + rand()%128 : '\n');

        DrawText(hDC, &szText[0][0], 80*50, &pRect, DT_CENTER | DT_EXPANDTABS);

        Sleep(100);
    }
    return 0;
}

bool ParseVKey(int vKey)
{
    bool bKey = false;
    if(GetAsyncKeyState(vKey))
    if(GetAsyncKeyState(vKey))
        bKey = true;
    return bKey;
}
