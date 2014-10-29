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
typedef struct _file
{
	char fileName[MAX_BUFFER_SIZE];
	struct file *prev;
	struct file *next;
};
typedef struct _file file;

/* File Functions */
int FindFiles(file **first, file **last);

/* Linked List Functions */
int InsertIntoList(const char *fileName, file **head, file **tail);
void PrintList(file **head, file **tail);

/* Utility Functions */
void GetDirectory(char *buffer);
void RemoveEOL(char *buffer);
int ChangeDirectoryContext (const char *directory);
int GetNum();
void PrintMenu();