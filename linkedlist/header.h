/**
 *	This program is designed to demonstrate a simple double linked list. It
 *	does this by scanning a directory for files and inserting the file names
 *	into a linked list and then printing them back out. The directory is
 *	decided by input from the user.
 */

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <direct.h>

#define MAX_BUFFER_SIZE 255


/**
 * Definition for linked list elements
 */
typedef struct _llelement
{
	void * data;
	struct llelement *prev;
	struct llelement *next;
};
typedef struct _llelement llelement;

/**
 * Definition for hold file data
 */
typedef struct _fileData
{
	char *name;
};
typedef struct _fileData fileData;

/* File Functions */
int FindFiles(llelement **first, llelement **last);

/* Linked List Functions */
llelement *AllocateSpace(int data);
void *GetDataAddress(void *p);
int InsertIntoList(llelement *toInsert, llelement **head, llelement **tail);
void PrintList(llelement **head, llelement **tail);

/* Utility Functions */
void GetDirectory(char *buffer);
void RemoveEOL(char *buffer);
int ChangeDirectoryContext (const char *directory);
int GetNum();
void PrintMenu();