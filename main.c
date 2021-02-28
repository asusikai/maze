#include "header.h"
#include "header.h"


int main()
{
    int x=0,y=0;

    LoadMaze();

    CursorView(0);

    while(1)
    {
        PrintMaze();

        move_cursor(&x, &y);
    }

    return 0;
}
