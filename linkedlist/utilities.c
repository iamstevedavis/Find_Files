#include "header.h"

/**
 *	Prompts the user to enter a directory and then stores the input for
 *	later use.
 *
 *	Parameters
 *		char *buffer
 *			A char array for fgets to store user input in
 *
 *	Returns
 *		None
 */
void GetDirectory(char *buffer)
{
	printf("Please enter a directory (or \"9\" to return to main menu): ");
	fgets(buffer, MAX_BUFFER_SIZE, stdin);
}

/**
 *	Removes the EOL character from a char array.
 *
 *	Parameters
 *		char *buffer
 *			A char array to remove the EOL character from
 *
 *	Returns
 *		None
 */
void RemoveEOL(char *buffer)
{
	char *target = strchr(buffer, '\n');

	if(NULL != target)
	{
		*target = '\0';
	}
}

/**
 *	Changes the directory context. Required so the user can specify the
 *	directory they would like to find files in.
 *
 *	Parameters
 *		const char *directory
 *			A char array that contains the directory. Note the const - no changes
 *			will be made to the char array in this function.
 *
 *	Returns
 *		_chdir(directory)
 *			The response from _chdir. Tells us if the directory change was successful.
 */
int ChangeDirectoryContext (const char *directory)
{
	return _chdir(directory);
}

/**
 *	Prompts the user to enter a directory and then stores the input for
 *	later use.
 *
 *	Parameters
 *		char *buffer
 *			A char array for fgets to store user input in
 *
 *	Returns
 *		None
 */
int GetNum(void)
{
	char record[4] = {0};
	int number = 0;

	fgets(record,  sizeof(record), stdin);

	if(  sscanf_s(record, "%d", &number) != 1 )
	{
		return -1;
	}

	return  number;
}

/**
 *	Prints the menu.
 *
 *	Parameters
 *		None
 *
 *	Returns
 *		None
 */
void PrintMenu()
{
	printf("\nMenu:\n");
	printf("==========\n");
	printf("1: Load Directory\n");
	printf("2: Print Current List\n");
	printf("9: Exit\n");
	printf("==========\n\n");
}