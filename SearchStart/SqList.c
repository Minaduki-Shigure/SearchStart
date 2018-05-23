#include "SqList.h"

void BubbleSort(TElemType num[], int length)
{
	int a, b;
	TElemType t;
	for (a = 0; a < length; a++)
	{
		for (b = a; b < length; b++)
		{
			if (num[a] > num[b])
			{
				t = num[a];
				num[a] = num[b];
				num[b] = t;
			}
		}
	}
}

SqList TableInit(int length, int input[])
{
	SqList table;
	table.length = length;
	table.list = (TElemType*)malloc(table.length * sizeof(TElemType));
	if (!table.length)
		exit(-1);
	int i = 0;
	int j = 0;
	int k = 0;
	int buffer = 0;
	BubbleSort(input, table.length);
	for (i = 0; i < table.length; i++)
		table.list[i] = input[i];
	return table;
}

void TablePrint(SqList table)
{
	int i = 0;
	for (i = 0; i < table.length; i++)
		printf("%d ", table.list[i]);
	putchar('\n');
	return;
}

int BinarySearch(SqList table, TElemType key)
{
	int low = 0;
	int mid = 0;
	int high = table.length - 1;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (key == table.list[mid])
			return mid;
		else if (key < table.list[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}