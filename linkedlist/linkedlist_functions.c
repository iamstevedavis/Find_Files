#include "header.h"

/**
 *	Allocates memory equal to your data size + a llelement
 *
 *	Parameters
 *		int data
 *			An integer representing how many bytes of data you need
 *
 *	Returns
 *		llelement * that represents the start of the block of memory of llelement + your data space
 */
llelement *AllocateSpace(int data)
{
	llelement *tmp = NULL;
	tmp = (llelement*)malloc(sizeof(llelement) + data);
	return tmp;
}

/**
 *	Returns the address at which you can start writing data.
 *
 *	Parameters
 *		void *p
 *			The address that represents the start of the memory block containing an llelement
 *
 *	Returns
 *		void * that is the location you can start writing data to
 */
void *GetDataAddress(void *p)
{
	void *tmp = NULL;
	tmp = ((llelement*)p + sizeof(llelement*));
	return tmp;
}

/**
 *	Inserts a llelement struct into the linked list.
 *
 *	Parameters
 *		const char *llelementName
 *			A char array that contains the llelementname we want to insert
 *		llelement **head
 *			This is the value of the current location of the head of the linked list
 *		llelement **tail
 *			This is the value of the current location of the tail of the linked list
 *
 *	Returns
 *		0 on successful insertion
 */
int InsertIntoList(llelement *toInsert, llelement **head, llelement **tail)
{
	llelement *previousllelement = NULL;
	llelement *nextllelement = NULL;

	toInsert->next = toInsert->prev = NULL; /* Set the next and prev to null for the new llelement because we don't yet know what is prev and what is next */

	if(NULL == toInsert)
	{
		return -1;
	}

	/**
	 *	We are inserting the first item in the list
	 */
	if(NULL == *head)
	{
		*head = toInsert;
		*tail = toInsert;
		return 0;
	}
	/**
	 *	We are inserting at the end of the list
	 */
	else
	{
		previousllelement = *head;
		nextllelement = previousllelement->next;

		/**
		 *	Go to the end of the list
		 */
		while(NULL != nextllelement)
		{
			previousllelement = nextllelement;
			nextllelement = nextllelement->next;
		}

		/**
		 * We are at the end of the list so add the new llelement
		 */
		if(NULL == nextllelement)
		{
			*tail = toInsert;
			toInsert->next = NULL;
			previousllelement->next = toInsert;
			toInsert->prev = previousllelement;
		}
	}

	return 0;
}

/**
 *	Prints the contents of the linked list to the console
 *
 *	Parameters
 *		llelement **head
 *			This is the value of the current location of the head of the linked list
 *		llelement **tail
 *			This is the value of the current location of the tail of the linked list
 *
 *	Returns
 *		None
 */
void PrintList(llelement **head, llelement **tail)
{
	llelement *previousllelement = NULL;
	llelement *nextllelement = NULL;
	void *p;
	int len = 0;
	fileData *pFileData = NULL;

	/**
	 *	Check for empty list
	 */
	if(NULL == *head)
	{
		printf("Empty List!\n");
		return;
	}

	previousllelement = *head;
	nextllelement = previousllelement->next;

	while(NULL != nextllelement)
	{
		p = GetDataAddress(previousllelement);
		pFileData = (fileData*)p;
		printf("%s\n", pFileData->name);
		previousllelement = nextllelement;
		nextllelement = nextllelement->next;
	}

	if(NULL == nextllelement)
	{
		return;
	}
}