#include "header.h"

int FindFiles(file **head, file **tail)
{
	int validatorInt = 0;

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile("*", &FindFileData);

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