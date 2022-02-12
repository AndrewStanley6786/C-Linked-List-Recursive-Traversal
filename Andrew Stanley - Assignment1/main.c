// Andrew Stanley
// PROG72365
// Assignment 1
// Feb. 2022

#include "main.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	int numOfUsers = atoi(argv[1]);		// Taking command line argument for amount of users to create
	Queue* myQueue = NULL;
	myQueue = (Queue*)malloc(sizeof(Queue));		// Creating the queue

	InitQueue(myQueue);			// Initializing queue

	IsQueueEmpty(myQueue);		// Check to see if queue is empty
	
	AddUsers(myQueue, numOfUsers);		// Adding the users using the amount requested in command line

	for (int i = 0; i < numOfUsers; i++)
	{
		Node* deletedNode = DeQueue(myQueue);		

		printf("Deleted User's Inofrmation:\n");		//Pringting dequeued node's information
		printf("User Name: %s\n", deletedNode->userInfo->userName);
		printf("Level: %d\n", deletedNode->userInfo->level);

		if (deletedNode->userInfo->faction == 0)		// Different prints for each faction
			printf("Faction: %s\n\n", "Red");
		else if (deletedNode->userInfo->faction == 1)
			printf("Faction: %s\n\n", "Green");
		else
			printf("Faction: %s\n\n", "Blue");

		free(deletedNode);
	}

	free(myQueue);

	return 0;
}

