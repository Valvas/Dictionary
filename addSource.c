#include "functions.h"

/**

1 - Get the name of the new source file (without path of the file)

WARNING - This file must be placed in folder "sources" in the executable folder

2 - Get the path of the folder "sources" and copy it in string 'folderPath'
3 - Concatenate 'folderPath' and the name of the new source file

EXEMPLE - folderPath -> "sources/" + fileName -> "test.txt" = folderPath -> "sources/test.txt"

4 - Check if source file is not already in the linked list(consequently in LIST_FILE) by calling 'checkSourceExistence.c' (return 0 if already exists)
5 - Check if file exists and can be read (return 1 if yes and 0 if no)
6 - Add the new source file in LIST_FILE (constant defined in "functions.h") by calling 'addSourceInList.c' (return 1 if data is added)
7 - If 'addSourceInList' returned 1, create a new element 'source' to add in the linked list
8 - If element successfully added in linked list, print confirmation

**/

void addSource(source* firstSource)
{
	char fileName[NAME_SIZE_NO_PATH];
	char folderPath[NAME_SIZE];
	
	source* src = NULL;
	
	CLEAR
	
	printf("========================================\n\n");
	printf("Enter the name of the source file (without path) : ");
	
	/** Step 1 **/
	entry(fileName,NAME_SIZE_NO_PATH);
	
	/** Step 2 **/
	strcpy(folderPath,SOURCE_FOLDER_PATH);
	
	/** Step 3 **/
	strcat(folderPath,fileName);
	
	/** Step 4 **/
	if(checkSourceExistence(firstSource,folderPath))
	{
		/** Step 5 **/
		if(checkFile(folderPath))
		{
			/** Step 6 **/
			if(addSourceInList(folderPath))
			{
				/** Step 7 **/
				src = newSource(firstSource,folderPath);
				
				/** Step 8 **/
				if(src != NULL)
				{
					printf("\nSUCCESS : new source created !\n");
					printf("\nPress enter to continue...");
					getchar();
				}
			}
		}
	}
}