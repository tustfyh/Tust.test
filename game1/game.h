#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void one_game(char arr[ROW][COL], int row, int col);
void two_game(char arr[ROW][COL], int row, int col);
void playmove(char arr[ROW][COL], int row, int col);
void computermove(char arr[ROW][COL], int row, int col);
char win(char arr[ROW][COL], int row, int col);