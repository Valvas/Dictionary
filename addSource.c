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
8 - Open source file in order to get all its content and create a structure 'word' for each line
9 - Get each line of the source file while some remain
10 - Call "getWord.c" that will create a structure 'word' for each line of the source file and add them in the word linked list

**/

void addSource(head* listHead, primary* firstWord)
{
	char fileName[NAME_SIZE_NO_PATH];
	char folderPath[NAME_SIZE];
	
	CLEAR
	
	printf("============================================================\n\n");
	printf("Enter the name of the source file (without path) : ");
	
	/** Step 1 **/
	entry(fileName,NAME_SIZE_NO_PATH);
	
	/** Step 2 **/
	strcpy(folderPath,SOURCE_FOLDER_PATH);
	
	/** Step 3 **/
	strcat(folderPath,fileName);
	
	/** Step 4 **/
	if(checkSourceExistenceForAdding(listHead,folderPath))
	{
		/** Step 5 **/
		if(checkFile(folderPath))
		{
			/** Step 6 **/
			if(addSourceInList(folderPath))
			{
				/** Step 7 **/
				if(newSource(listHead,folderPath))
				{
					FILE* file = NULL;
					
					/** Step 8 **/
					file = fopen(folderPath,"r");
					
					if(file != NULL)
					{
						char content[DEFINITION];
						
						/** Step 9 **/
						while(fgets(content,DEFINITION,file) != NULL)
						{
							/** Step 10 **/
							createWord(firstWord,content);
						}
						
						fclose(file);
						
						CLEAR
						printf("\nSUCCESS : source created !\n");
						printf("\nSUCCESS : content from source file correctly added in program !\n");
						printf("\nPress enter to continue...");
						getchar();
					}
					
					else
					{
						CLEAR
						printf("\nSUCCESS : source created !\n");
						printf("\nERROR : cannot read content of the new source file !\n");
						printf("\nPress enter to continue...");
						getchar();
					}
				}
			}
		}
	}
}