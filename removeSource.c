#include "functions.h"

/**

INFO -	This function removes a source from the linked list and if it succed calls function "removeSourceInList.c" that will remove source from LIST_FILE
		(constant defined in "functions.h")
		
		It gets two parameters :
			
			- The first source in the linked list
			- The source selected that must be removed
			
		It returns 1 if source is removed and 0 if something went wrong
			
1 - Check if source to remove is the first source

	1.1 - Check if there is a next source after 'firstSource'
	1.2 - Set 'firstSource' the next source, so linked list starts now at the second source, the previous first source is not an element of the list anymore
	
2 - Check if 'tmpSource' is not null
3 - Loop to browse the linked list while there is a next source in the list and the next source is not the source to remove
	Once the loop ends 'tmpSource' = source which precedes source to remove

	3.1 - If the next source is not the source to remove, set 'tmpSource' the next source

4 - Check if there is a source next to the source to remove in order to link the previous source with the next

	EXAMPLE : 1 -> 2 -> 3 -> 4 || source to remove : 3 || 1 -> 2 -> 4
	
	4.1 - Jump source to remove by connecting previous source of source to remove with its next source
	4.2 - Set the next source of the source to remove to null, so source to remove is not linked to the list by anyway
	
5 - If the source to remove is the last of the linked list, break the link with the previous one

	EXAMPLE : 1 -> 2 -> 3 || source to remove : 3 || 1 -> 2 -> NULL

**/

int removeSource(head* listHead, source* removedSource)
{	
	/** Step 1 **/
	if(listHead->sourceTarget == removedSource)
	{		
		/** Step 1.1 **/
		if(listHead->sourceTarget->nextSource)
		{
			/** Step 1.2 **/
			listHead->sourceTarget = listHead->sourceTarget->nextSource;
		}
		
		else
		{
			listHead->sourceTarget = NULL;
		}
		
		return 1;
	}
	
	else
	{
		source* tmpSource = listHead->sourceTarget;
	
		/** Step 2 **/
		if(tmpSource)
		{
			/** Step 3 **/
			while(tmpSource->nextSource && tmpSource->nextSource != removedSource)
			{
				/** Step 3.1 **/
				tmpSource = tmpSource->nextSource;
			}
		
			/** Step 4 **/
			if(removedSource->nextSource)
			{
				/** Step 4.1 **/
				tmpSource->nextSource = removedSource->nextSource;
				
				/** Step 4.2 **/
				removedSource->nextSource = NULL;
			}
		
			/** Step 5 **/
			else
			{
				tmpSource->nextSource = NULL;
			}
		
			return 1;
		}
	
		else
		{
			CLEAR
			printf("\nERROR : cannot create temporary source element !\n");
			printf("\nPress enter to continue...");
			getchar();
			return 0;
		}
	}
}