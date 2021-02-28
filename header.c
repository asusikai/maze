//header.c
#include "header.h"
#include "header.h"

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void move_cursor(int* row, int* col) // xy�� ���� Ŀ�� ��ġ
{
    int key;

    if (_kbhit()) // Ű���带 ������ ��
    {
        key = _getch();

        if (key = ARROW) // Ȯ�� �ƽ�Ű �ڵ忡�� ����Ű�� �ǹ��ϴ� ���� �Է¹޴´�.
        {
			key = _getch(); // ������ �ǹ��ϴ� �� �ޱ�

            switch(key)
            {
                case UP:
                    if (!(IsBlock(*row - 1, *col)))
                    {
                        maze[*row][*col] = '0';
                        maze[*row - 1][*col] = 'x';
                        *row -= 1;

                        if (IsFinish(*row, *col))
                        {
                            Complete();
                        }
                    }

                    break;

                case DOWN:
                    if (!(IsBlock(*row + 1, *col)))
                    {
                        maze[*row][*col] = '0';
                        maze[*row + 1][*col] = 'x';
                        *row += 1;

                        if (IsFinish(*row , *col))
                        {
                            Complete();
                        }
                    }
                    break;

                case LEFT:
                    if (!(IsBlock(*row , *col-1)))
                    {
                        maze[*row][*col] = '0';
                        maze[*row ][*col-1] = 'x';
                        *col -= 1;

                        if (IsFinish(*row, *col))
                        {
                            Complete();
                        }
                    }

                    break;

                case RIGHT:
                    if (!(IsBlock(*row, *col+1)))
                    {
                        maze[*row][*col] = '0';
                        maze[*row][*col+1] = 'x';
                        *col += 1;

                        if (IsFinish(*row, *col))
                        {
                            Complete();
                        }
                    }

                    break;

            }
        }
    }
}

void PrintMaze()
{
    int i,j;
    for (i = 0; i < SIZE; i++)
    {
        GotoXY(XP, YP + i);

        for (j = 0; j < SIZE; j++)
        {
            if (maze[i][j] == '1')
            {
                printf("��");
            }

            else if (maze[i][j] == 'y')
            {
                printf("��");
            }

            else if (maze[i][j] == '0')
            {
                printf("��");
            }

            else
            {
                printf("��");
            }

        }

        puts("");
    }
}
void LoadMaze()
{
	char path[25] = "./Maze";
    char level;
    int i,j;

    printf("���̵��� �����ϼ���. (1, 2, 3) ");

	scanf("%c", &level);

	printf("lvl : %c\n", level);

	strcat(path, &level);
	strcat(path, ".txt");

	printf("path : %s\n", path); // ���ڿ��� �̾�ٿ��� ��� ����

	FILE* f = fopen(&path, "r"); // �Է¹��� path�� ���Ͽ���

	char str_tmp[50] = {0, }; //�Է� ���� f ���� ����


	for(i =0; i<SIZE; i++)
	{
		fgets(str_tmp, 50, f);
		char *ptr =strtok(str_tmp, "\t"); // str_tmp �ȿ��� tab������ ������ ptr �ȿ� ����
		for(j =0; j<SIZE; j++)
		{
			maze[i][j] = *ptr; //maze �ȿ� ����
			ptr = strtok(NULL, "\t"); //���� ���� ������ SIZE ��ŭ �ݺ�
		}
	}

	fclose(f);
}

int IsBlock(int i, int j)
{
    if (maze[i][j] == '1' || maze[i][j] == 'y')
        return 1;
    else
        return 0;
}

int IsFinish(int i, int j)
{
    if (maze[i][j] == 'y')
        return 1;
    else
        return 0;
}

void Complete()
{
    _end = clock();
    res = (float)(_end - start) / CLOCKS_PER_SEC;

    GotoXY(XP, YP + SIZE);
    printf("Complete!\n");
    GotoXY(XP, YP + SIZE + 1);
    printf("����ð� : %.2f��", res);
    exit(0);
}
