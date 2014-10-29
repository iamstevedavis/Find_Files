#include "header.h"

/**
 *	Finds the files in the directory that currently has focus.
 *
 *	Parameters
 *		file **head
 *			This is the value of the current location of the head of the linked list. This
 *			is only passed in here so we can pass it on to InsertIntoList.
 *		file **tail
 *			This is the value of the current location of the tail of the linked list. This
 *			is only passed in here so we can pass it on to InsertIntoList.
 *
 *	Returns
 *		0 if we successfully found all the files and added them to the list
 */
int FindFiles(file **head, file **tail)
{
	int validatorInt = 0;

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
		validatorInt = InsertIntoList((const char *)FindFileData.cFileName, head, tail); /* Insert the file we found into the list */
		if(0 != validatorInt)
		{
			printf("Could not store file in memory.");
			return -1;
		}
	}
	while (0 != FindNextFile(hFind, &FindFileData));

	return 0;
}