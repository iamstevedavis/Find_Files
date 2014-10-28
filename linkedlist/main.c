#include "header.h"

int main(int argc, char *argv[])
{
	char buffer[MAX_BUFFER_SIZE];
	int validatorInt = 0;

	file *head = NULL;
	file *tail = NULL;

	while(1)
	{
		do
		{
			GetDirectory(buffer);
			RemoveEOL(buffer);
			validatorInt = ChangeDirectoryContext(buffer);
			if(0 != validatorInt)
			{
				printf("Could not find the directory specified.\n");
			}
		}
		while (0 != validatorInt);
		printf("Directory \"%s\" found.\n", buffer);
		FindFiles(head, tail);
	}
}

void PrintList(file *head, file *tail)
{
	do
	{

	}
	while(1);
}

int FindFiles(file **head, file **tail)
{
	int validatorInt = 0;

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile("\\*", &FindFileData);

	if (INVALID_HANDLE_VALUE == hFind) 
	{
		printf ("FindFirstFile failed (%d)\n", GetLastError());
		return -1;
	}

	do
	{
		validatorInt = InsertIntoList((char *)FindFileData.cFileName, head, tail);
		if(0 != validatorInt)
		{
			printf("Could not store file in memory.");
			return -1;
		}
	}
	while (0 != FindNextFile(hFind, &FindFileData));

	return 0;
}

#pragma warning( push )
#pragma warning( disable : 4133 )
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

	if(NULL == head)
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
			tail = newFile;
			newFile->next = NULL;
			previousFile->next = newFile;
			newFile->prev = previousFile;
		}
	}

	return 0;
}
#pragma warning( pop ) 

void GetDirectory(char *buffer)
{
	printf("Directory: ");
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