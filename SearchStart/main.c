#include "SqList.h"

int main(void)
{
	SqList table;
	int length = 0;
	TElemType input[MAX_LENGTH] = { 0 };
	printf("Please enter the length of the data:");
	scanf("%d", &length);
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("Please enter the data No.%d:", i + 1);
		scanf("%d", &input[i]);
	}
	table = TableInit(length, input);
	puts("Init success!");
	TablePrint(table);
	TElemType key = 0;
	int result = 0;
	printf("Please enter the data you would like to find:");
	scanf("%d", &key);
	result = BinarySearch(table, key);
	if (result == -1)
		puts("нч©и╥Н╦Ф");
	else
		printf("The data is the No.%d data of the input.\n", result + 1);
	system("pause");
	return 0;
}