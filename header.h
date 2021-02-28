//header.h
#ifndef header
#define header

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define XP 40
#define YP 5
#define SIZE 19

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224 

char maze[SIZE][SIZE];

clock_t start, _end;
float res;


void GotoXY(int x, int y);

void CursorView(char show);
void PrintMaze();
void LoadMaze();


void move_cursor(int* x, int* y);

int IsBlock(int i, int j);
int IsFinish(int i, int j);
void Complete();

#endif
