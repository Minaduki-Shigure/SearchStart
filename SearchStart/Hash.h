#pragma once

#include<stdio.h>
#include<stdlib.h>

#define HASH_SIZE 10

typedef struct HashNode{
	int number;
	HashNode *next;
}HashNode;

HashNode* NodeInit(void);