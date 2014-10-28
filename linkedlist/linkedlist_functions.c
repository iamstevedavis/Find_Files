#include "header.h"

int InsertIntoList(char *fileName, file **head, file **tail)
{
	file *newFile = NULL;
	file *previousFile = NULL;
	file *nextFile = NULL;

	newFile = (file *)malloc(sizeof(file));

	newFile->next = newFile->prev = NULL;

	if(NULL == newFile)
	{
		return -1;
	}

	strcpy_s(newFile->fileName, MAX_BUFFER_SIZE, fileName);

	if(NULL == *head)
	{
		*head = newFile;
		*tail = newFile;
		return 0;
	}
	else
	{
		previousFile = *head;
		nextFile = previousFile->next;

		while(NULL != nextFile)
		{
			previousFile = nextFile;
			nextFile = nextFile->next;
		}

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

void PrintList(file **head, file **tail)
{
	file *previousFile = NULL;
	file *nextFile = NULL;

	previousFile = *head;
	nextFile = previousFile->next;

	if(NULL == *head)
	{
		printf("Empty List!\n");
		return;
	}

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