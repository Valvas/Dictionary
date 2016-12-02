#include "functions.h"

/**

INFO -	This function prints all sources of the linked list and asks user for a source to remove

1 - Print sources of the linked list
2 - Ask user for a value (source to remove)
3 - Call functions which checks if entered value is a source in the linked list and get 1 if it is

**/

void deleteSource(source* firstSource)
{
	int count = 1;
	char name[NAME_SIZE];
	
	/** Step 1 **/
	CLEAR
	
	printf("============================================================\n");
	
	showSources(firstSource,&count);
	
	printf("============================================================\n");
	
	printf("\nEnter the source to delete : ");
	
	/** Step 2 **/
	entry(name,NAME_SIZE);
	
	/** Step 3 **/
	if(checkSourceExistenceForRemoving(firstSource,name))
	{
		CLEAR
		printf("\nSUCCESS : source removed from linked list !\n");
		printf("\nPress enter to continue...");
		getchar();
	}
}