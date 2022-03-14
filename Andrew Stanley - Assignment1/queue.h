// Andrew Stanley
// PROG72365
// Assignment 2
// Mar. 2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_FACTIONS 3
#define LEVEL_CAP 60

typedef enum Faction { red, green, blue } Faction;

typedef struct user
{
	char userName[11];
	int level;
	Faction faction;
} User;

typedef struct node
{
	User* userInfo;
	struct node* pNext;
} Node;

typedef struct queue
{
	Node* pHead;
	Node* pTail;
} Queue;

void InitQueue(Queue* myQueue);
int IsQueueEmpty(Queue* myQueue);
void AddToQueue(Queue* myQueue, Node* pTest);
Node* DeQueue(Queue* myQueue);
Queue* AddUsers(Queue* myQueue, int numOfUsers);

// Assignment 2
void traverse(Node* pCurrent);
void traverseR(Node* pCurrent);
void visit(Node* pCurrent);


