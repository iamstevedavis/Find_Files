#include "header.h"

/**
 *	Inserts a file struct into the linked list.
 *
 *	Parameters
 *		const char *fileName
 *			A char array that contains the filename we want to insert
 *		file **head
 *			This is the value of the current location of the head of the linked list
 *		file **tail
 *			This is the value of the current location of the tail of the linked list
 *
 *	Returns
 *		0 on successful insertion
 */
int InsertIntoList(const char *fileName, file **head, file **tail)
{
	file *newFile = NULL;
	file *previousFile = NULL;
	file *nextFile = NULL;

	newFile = (file *)malloc(sizeof(file)); /* Get some memory for the struct we are going to insert */

	newFile->next = newFile->prev = NULL; /* Set the next and prev to null for the new file because we don't yet know what is prev and what is next */

	if(NULL == newFile)
	{
		return -1;
	}

	strcpy_s(newFile->fileName, MAX_BUFFER_SIZE, fileName); /* Copy the filename into the struct we are going to insert */

	/**
	 *	We are inserting the first item in the list
	 */
	if(NULL == *head)
	{
		*head = newFile;
		*tail = newFile;
		return 0;
	}
	/**
	 *	We are inserting at the end of the list
	 */
	else
	{
		previousFile = *head;
		nextFile = previousFile->next;

		/**
		 *	Go to the end of the list
		 */
		while(NULL != nextFile)
		{
			previousFile = nextFile;
			nextFile = nextFile->next;
		}

		/**
		 * We are at the end of the list so add the new file
		 */
		if(NULL == nextFile)
		{
			*tail = newFile;
			newFile->next = NULL;
			previousFile->next = newFile;
			newFile->prev = previousFile;
		}
	}

	return 0;
}

/**
 *	Prints the contents of the linked list to the console
 *
 *	Parameters
 *		file **head
 *			This is the value of the current location of the head of the linked list
 *		file **tail
 *			This is the value of the current location of the tail of the linked list
 *
 *	Returns
 *		None
 */
void PrintList(file **head, file **tail)
{
	file *previousFile = NULL;
	file *nextFile = NULL;

	/**
	 *	Check for empty list
	 */
	if(NULL == *head)
	{
		printf("Empty List!\n");
		return;
	}

	previousFile = *head;
	nextFile = previousFile->next;

	while(NULL != nextFile)
	{
		printf("%s\n", previousFile->fileName);
		previousFile = nextFile;
		nextFile = nextFile->next;
	}

	if(NULL == nextFile)
	{
		return;
	}
}