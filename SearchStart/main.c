#include "SqList.h"

int a[8] = { 1,3,9,11,13,15,17,21 };
int ha1[10] = { 0 };

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
		puts("无可奉告");
	else
		printf("The data is the No.%d data of the input.\n", result + 1);
	double asl = (1 * 1 + 2 * 2 + 3 * 4 + 4 * 1) / 8.0;
	printf("The value of ASL is %lf.\n", asl);
	system("pause");
	puts("Now start the Hash table part.");
	int mod = 0;
	for (i = 0; i < 8; i++)
	{
		mod = a[i] % 10 - 1;
		while (1)
		{
			if (ha1[mod] != 0)
				mod++;
			else
			{
				ha1[mod] = a[i];
				break;
			}
		}
	}
	printf("线性探测再散列哈希表为：");
	for (i = 0; i < 10; i++)
		printf("%d ", ha1[i]);
	putchar('\n');
	printf("请输入查找的元素:");
	int n = 0;
	scanf("%d", &n);
	int flag = 0;
	for (i = 0; i < 10; i++)
	{
		if (ha1[i] == n)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		printf("找到元素，在第%d位\n", i + 1);
	else
		puts("无可奉告");
	puts("ASL值为1.875");
	system("pause");
	puts("Now start the advance part");
	HashNode *p = NodeInit();
	printf("请输入查找的元素:");
	scanf("%d", &n);
	mod = n % 10;
	flag = 0;
	HashNode *s = p[mod - 1].next;
	for (; s != NULL; s = s->next)
	{
		if (s->number == n)
			flag = 1;
	}
	for (i = 0; i < 10; i++)
	{
		HashNode *s = p[i].next;
		for (; s != NULL; s = s->next)
			printf("%d->", s->number);
		putchar('\n');
	}
	if (flag == 1)
		puts("找到元素");
	else
		puts("无可奉告");
	puts("ASL值为1.5");
	system("pause");
	return 0;
}