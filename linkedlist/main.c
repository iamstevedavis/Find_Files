#include "header.h"

int main(int argc, char *argv[])
{
	char buffer[MAX_BUFFER_SIZE];
	int validatorInt = 0;

	file *first = NULL;
	file *last = NULL;

	while(1)
	{
		do
		{
			GetDirectory(buffer);
			RemoveEOL(buffer);
			validatorInt = ValidateDirectory(buffer);
			if(0 != validatorInt)
			{
				printf("Could not find the directory specified.\n");
			}
		}
		while (0 != validatorInt);
		printf("Directory \"%s\" found.\n", buffer);
		FindFiles(first, last);
	}
}

void PrintList(file *first, file *last)
{
	do
	{

	}
	while(1);
}

int FindFiles(file *first, file *last)
{
	int validatorInt = 0;

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile((LPCWSTR)"\\*", &FindFileData);

	if (INVALID_HANDLE_VALUE == hFind) 
	{
		printf ("FindFirstFile failed (%d)\n", GetLastError());
		return -1;
	}

	do
	{
		validatorInt = InsertIntoList((char *)FindFileData.cFileName, first, last);
		if(0 != validatorInt)
		{
			printf("Could not store file in memory.");
			return -1;
		}
	}
	while (0 != FindNextFile(hFind, &FindFileData));
	return 0;
}

int InsertIntoList(char *fileName, file *first, file *last)
{
	file *newFile = NULL;
	file *previousFile = NULL;
	file *nextFile = NULL;

	newFile->next = newFile->prev = NULL;

	newFile = (file *)malloc(sizeof(file));

	if(NULL == newFile)
	{
		return -1;
	}

	strcpy(newFile->fileName, fileName);

	if(NULL == first)
	{
		first = last = newFile;
		return 0;
	}
	else
	{
		previousFile = first;
		nextFile = previousFile->next;
		while(NULL != nextFile)
		{
			previousFile = nextFile;
			nextFile = nextFile->next;
		}

		if(NULL == nextFile)
		{
			last = newFile;
			newFile->next = NULL;
			previousFile->next = newFile;
			newFile->prev = previousFile;
		}
	}
	return 0;
}

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

int ValidateDirectory (const char *directory)
{
	return _chdir(directory);
}