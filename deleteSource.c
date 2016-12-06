#include "functions.h"

/**

INFO -	This function prints all sources of the linked list and asks user for a source to remove

1 - Print sources of the linked list
2 - Ask user for a value (source to remove)
3 - Call function which checks if entered value is a source in the linked list and get 1 if it is
4 - Call function which remove the line corresponding to the source to remove in LIST_FILE (constant defined in "functions.h")
5 - Loop that asks the user if he wants to remove the source file from folder source or just from program
6 - Get the user's choice
7 - Remove file from folder sources

**/

void deleteSource(head* listHead)
{
	int count = 1;
	char name[NAME_SIZE];
	
	/** Step 1 **/
	CLEAR
	
	printf("============================================================\n");
	
	if(listHead->sourceTarget) showSources(listHead->sourceTarget,&count);
	
	printf("============================================================\n");
	
	printf("\nEnter the source to remove from program : ");
	
	/** Step 2 **/
	entry(name,NAME_SIZE);
	
	/** Step 3 **/
	if(checkSourceExistenceForRemoving(listHead,name))
	{
		/** Step 4 **/
		if(removeSourceInList(name))
		{
			int size = 3;
			long choice = 0;
			
			/** Step 5 **/
			while(choice < 1 || choice > 2)
			{
				CLEAR
				
				printf("\nDo you want to remove the file from sources folder ?\n");
				printf("\n1. Yes");
				printf("\n2. No");
				
				printf("\n\nYour choice : ");
				
				/** Step 6 **/
				choice = integer(size);
				
				if(choice == 1)
				{
					/** Step 7 **/
					if(remove(name)){}

					CLEAR
					printf("\nSUCCESS : source file removed from sources folder !\n");
					printf("\nSUCCESS : source removed from linked list !\n");
					printf("\nSUCCESS : source removed from \"%s\" !\n",LIST_FILE);
					printf("\nPress enter to continue...");
					getchar();
				}
				
				else if(choice == 2)
				{
					CLEAR
					printf("\nSUCCESS : source removed from linked list !\n");
					printf("\nSUCCESS : source removed from \"%s\" !\n",LIST_FILE);
					printf("\nPress enter to continue...");
					getchar();
				}
				
				else
				{
					choice = 0;
				}
			}
		}
	}
}