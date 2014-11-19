#include "header.h"

/**
 *	Finds the files in the directory that currently has focus.
 *
 *	Parameters
 *		llelement **head
 *			This is the value of the current location of the head of the linked list. This
 *			is only passed in here so we can pass it on to InsertIntoList.
 *		llelement **tail
 *			This is the value of the current location of the tail of the linked list. This
 *			is only passed in here so we can pass it on to InsertIntoList.
 *
 *	Returns
 *		0 if we successfully found all the files and added them to the list
 */
int FindFiles(llelement **head, llelement **tail)
{
	int validatorInt = 0;

	char *name;
	void *p = NULL;
	fileData *pFileData = NULL;

	WIN32_FIND_DATA FindFileData; /* When we find a file, this is populated with that files data */
	HANDLE hFind; /* Handle to the file */

	hFind = FindFirstFile("*", &FindFileData);

	if (INVALID_HANDLE_VALUE == hFind) 
	{
		printf ("FindFirstFile failed (%d)\n", GetLastError());
		return -1;
	}

	do
	{
		p = AllocateSpace(sizeof(pFileData));
		pFileData = (fileData*)GetDataAddress(p);
		pFileData->name = (char *)malloc(sizeof(FindFileData.cFileName));
		strcpy_s(pFileData->name, MAX_BUFFER_SIZE, FindFileData.cFileName); /* Copy the filename into the struct we are going to insert */
		validatorInt = InsertIntoList((llelement *)p, head, tail); /* Insert the file we found into the list */
		if(0 != validatorInt)
		{
			printf("Could not store file in memory.");
			return -1;
		}
	}
	while (0 != FindNextFile(hFind, &FindFileData));

	return 0;
}