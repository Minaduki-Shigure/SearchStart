#include "Hash.h"

int a[8] = { 1,3,9,11,13,15,17,21 };

HashNode* NodeInit(void)
{
	HashNode *p = (HashNode*)malloc(HASH_SIZE * sizeof(HashNode));
	int i = 0;
	for (i = 0; i < HASH_SIZE; i++)
	{
		p[i].number = i + 1;
		p[i].next = NULL;
	}
	int mod = 0;
	for (i = 0; i < 8; i++)
	{
		mod = a[i] % HASH_SIZE;
		if (p[mod - 1].next == NULL)
		{
			HashNode *ass = (HashNode*)malloc(sizeof(HashNode));
			ass->number = a[i];
			ass->next = NULL;
			p[mod - 1].next = ass;
		}
		else
		{
			HashNode *q = p[mod - 1].next;
			for (; q->next != NULL; q = q->next);
			HashNode *ass = (HashNode*)malloc(sizeof(HashNode));
			ass->number = a[i];
			ass->next = NULL;
			q->next = ass;
		}
	}
	return p;
}