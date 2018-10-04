#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>

int main()
{
    POINT cursor;
    bool pressed = false;

    for (;;)
    {
        GetCursorPos(&cursor);

        if (GetKeyState(VK_F2) & 0x8000)
        {
            if (!pressed)
            {
                printf("move_mouse(%i, %i)\n", cursor.x, cursor.y);
                pressed = true;
            }
        }
        else if (GetKeyState(VK_F3) & 0x8000)
        {
            if (!pressed)
            {
                printf("left_click\n");
                pressed = true;
            }
        }
        else if (GetKeyState(VK_ESCAPE) & 0x8000)
        {
            break;
        }
        else
        {
            pressed = false;
        }
		Sleep(10);
    }

    return 0;
}
