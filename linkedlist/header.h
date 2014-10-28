
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <direct.h>

#define MAX_BUFFER_SIZE 255

typedef struct _file
{
	char fileName[MAX_BUFFER_SIZE];
	struct file *prev;
	struct file *next;
}file;

void GetDirectory(char *buffer);
void RemoveEOL(char *buffer);
int ChangeDirectoryContext (const char *directory);

void PrintList(file **head, file **tail);
int FindFiles(file **first, file **last);
int InsertIntoList(char *fileName, file **head, file **tail);

void PrintMenu();
int GetNum();