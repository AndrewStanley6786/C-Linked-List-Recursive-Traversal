// Andrew Stanley
// PROG72365
// Assignment 2
// Mar. 2022

#include "main.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	int numOfUsers = atoi(argv[1]);		// Taking command line argument for amount of users to create
	Queue* myQueue = NULL;
	myQueue = (Queue*)malloc(sizeof(Queue));		// Creating the queue

	srand(time(NULL));

	InitQueue(myQueue);			// Initializing queue

	IsQueueEmpty(myQueue);		// Check to see if queue is empty

	AddUsers(myQueue, numOfUsers);		// Adding the users using the amount requested in command line

	printf("RECURSIVE TRAVERSE: \n");
	traverse(myQueue->pHead);			// Calling recursive function

	printf("\nREVERSE RECURSIVE TRAVERSE:\n");
	traverseR(myQueue->pHead);			// Calling reverse recursive function

	printf("\nDEQUEUING NODES:\n");
	for (int i = 0; i < numOfUsers; i++)
	{
		Node* deletedNode = DeQueue(myQueue);
		printf("Deleted ");
		visit(deletedNode);				// Now using standard visit function, which prints user's information
		free(deletedNode);
	}

	free(myQueue);

	return 0;
}

