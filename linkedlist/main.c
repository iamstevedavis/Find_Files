#include "header.h"

int main(int argc, char *argv[])
{
	char buffer[MAX_BUFFER_SIZE];
	int validatorInt = 0;
	int exit = 0;

	file *head = NULL;
	file *tail = NULL;

	while(0 == exit)
	{
		PrintMenu();
		switch(GetNum())
		{
			case 1:
				GetDirectory(buffer);
				RemoveEOL(buffer);
				if(strcmp("9", buffer) == 0)
				{
					break;
				}
				validatorInt = ChangeDirectoryContext(buffer);
				if(0 != validatorInt)
				{
					printf("Could not find the directory specified.\n");
				}
				else
				{
					printf("Directory \"%s\" found.\n", buffer);
					FindFiles(&head, &tail);
					PrintList(&head, &tail);
				}
				break;

			case 2:

				break;

			case 9:
				exit = 1;
				break;

			default:
				break;
		}
	}
}