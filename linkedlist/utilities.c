#include "header.h"

void GetDirectory(char *buffer)
{
	printf("Please enter a directory (or \"9\" to return to main menu): ");
	fgets(buffer, MAX_BUFFER_SIZE, stdin);
}

void RemoveEOL(char *buffer)
{
	char *target = strchr(buffer, '\n');

	if(NULL != target)
	{
		*target = '\0';
	}
}

int ChangeDirectoryContext (const char *directory)
{
	return _chdir(directory);
}

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

void PrintMenu()
{
	printf("Menu:\n");
	printf("==========\n");
	printf("1: Load Directory\n");
	printf("2: Do Nothing\n");
	printf("9: Exit\n");
	printf("==========\n");
}