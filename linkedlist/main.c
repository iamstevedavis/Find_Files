#include "header.h"

/**
 *	Controls program flow. Program entry point.
 *
 *	Parameters
 *		None
 *
 *	Returns
 *		0 on successful execution
 */
int main(void)
{
	char buffer[MAX_BUFFER_SIZE]; /* A buffer of MAX_BUFFER_SIZE to hold user input */
	int validatorInt = 0; /* Used to validate return values from various function calls */
	int exit = 0; /* A flag that indicates if the user wants to exit the program */

	file *head = NULL;
	file *tail = NULL;

	/**
	 *	Menu loop
	 */
	while(0 == exit)
	{
		PrintMenu();
		switch(GetNum())
		{
			case 1:
				GetDirectory(buffer); /* Get directory from user */
				RemoveEOL(buffer); /* Remove EOL character from buffer */
				if(strcmp("9", buffer) == 0) /* User can exit to main menu with 9 so check for it */
				{
					break;
				}
				validatorInt = ChangeDirectoryContext(buffer); /* Change the directory context */
				if(0 != validatorInt)
				{
					printf("Could not find the directory specified.\n");
				}
				else
				{
					printf("Directory \"%s\" found.\n", buffer);
					validatorInt = FindFiles(&head, &tail); /* Find the files in the directory and put them in linked list */
					if(0 == validatorInt)
					{
						printf("List Populated.\n");
					}
					else
					{
						printf("Could not populate list. Please try a different directory.\n");
					}
				}
				break;

			case 2:
				PrintList(&head, &tail); /* Print the files from the linked list */
				break;

			case 9: /* Exit the program */
				exit = 1;
				break;

			default:
				break;
		}
	}
	return 0;
}