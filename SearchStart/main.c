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
		puts("�޿ɷ��");
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
	printf("����̽����ɢ�й�ϣ��Ϊ��");
	for (i = 0; i < 10; i++)
		printf("%d ", ha1[i]);
	putchar('\n');
	printf("��������ҵ�Ԫ��:");
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
		printf("�ҵ�Ԫ�أ��ڵ�%dλ\n", i + 1);
	else
		puts("�޿ɷ��");
	puts("ASLֵΪ1.875");
	system("pause");
	puts("Now start the advance part");
	HashNode *p = NodeInit();
	printf("��������ҵ�Ԫ��:");
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
		puts("�ҵ�Ԫ��");
	else
		puts("�޿ɷ��");
	puts("ASLֵΪ1.5");
	system("pause");
	return 0;
}