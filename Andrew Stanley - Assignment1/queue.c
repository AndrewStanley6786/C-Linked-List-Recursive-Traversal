// Andrew Stanley
// PROG72365
// Assignment 1
// Mar. 2022

#include "main.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitQueue(Queue* myQueue)
{
	myQueue->pHead = NULL;
	myQueue->pTail = NULL;
}

int IsQueueEmpty(Queue* myQueue)
{
	return (myQueue->pHead == NULL);
}

void AddToQueue(Queue* myQueue, Node* pCurrent)
{
	if (myQueue->pHead == NULL)		//If no nodes, pCurrent is head and tail
	{
		myQueue->pHead = myQueue->pTail = pCurrent;
	}
	else
	{
		myQueue->pTail->pNext = pCurrent;		//Otherwise add pCurrent to next to tail
	}
	pCurrent->pNext = NULL;
	myQueue->pTail = pCurrent;
}

Node* DeQueue(Queue* myQueue)
{
	Node* pTemp;
	if (myQueue->pHead == NULL) //If no more nodes, return null
		return(NULL);
	pTemp = myQueue->pHead;		// Dequeue from head
	myQueue->pHead = myQueue->pHead->pNext;
	return(pTemp);
}

Queue* AddUsers(Queue* myQueue, int numOfUsers)
{
	for (int i = 0; i < numOfUsers; i++)
	{
		Node* pCurrent = NULL;		//Placeholder node
		pCurrent = (Node*)malloc(sizeof(Node));
		if (!pCurrent)
		{
			printf("Error allocating memory");
			exit(1);
		}

		pCurrent->userInfo = (User*)malloc(sizeof(User));

		pCurrent->userInfo->faction = rand() % NUM_OF_FACTIONS;		// 3 so remainder will be between 0 & 2
		pCurrent->userInfo->level = (rand() % LEVEL_CAP) + 1;

		for (int i = 0; i < 11; i++)
		{
			if (i < 6)
				pCurrent->userInfo->userName[i] = 'A' + (rand() % 26);		// First 6 characters are a letter
			else if (i == 10)
				pCurrent->userInfo->userName[i] = '\0';						// Adding terminating character
			else
				pCurrent->userInfo->userName[i] = '0' + rand() % 10;		// Last 4 characters are a number
		}

		AddToQueue(myQueue, pCurrent);
	}
	return myQueue;
}

// Assignment 2
void visit(Node* pCurrent)				// General print function to print for each type of traverse
{
	printf("User's Inofrmation:\n");		//Printing node's information
	printf("User Name: %s\n", pCurrent->userInfo->userName);
	printf("Level: %d\n", pCurrent->userInfo->level);

	if (pCurrent->userInfo->faction == red)		// Different prints for each faction
		printf("Faction: %s\n\n", "Red");
	else if (pCurrent->userInfo->faction == green)
		printf("Faction: %s\n\n", "Green");
	else
		printf("Faction: %s\n\n", "Blue");
}

void traverse(Node* pCurrent)
{
	if (pCurrent == NULL)
		return;
	visit(pCurrent);			// Visit before recursion
	traverse(pCurrent->pNext);
}

void traverseR(Node* pCurrent)
{
	if (pCurrent == NULL)
		return;
	traverseR(pCurrent->pNext);
	visit(pCurrent);			// Visit after recursion
}
