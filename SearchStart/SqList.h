#pragma once

#include<stdio.h>
#include<stdlib.h>

#define MAX_LENGTH 100

typedef int TElemType;

typedef struct {
	TElemType *list;
	int length;
}SqList;

void BubbleSort(TElemType num[], int length);
SqList TableInit(int length, int input[]);
void TablePrint(SqList table);
int BinarySearch(SqList table, TElemType key);