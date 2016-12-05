#include "functions.h"

/**

INFO -	This function get the content of LIST_FILE (constant defined in "functions.h") without the line corresponding to the source to remove and rewrite
		the file with this content
		
1 - Open LIST_FILE in read-only mode in order to get the content of the file
2 - Create an array which size is equal to the number of characters in LIST_FILE by using "getFileSize.c"
3 - Empty array 'content' by setting the first character equals to '\0'
4 - Check if file is correctly open, if not call 'else' for error message and exiting program
5 - Loop that executes itself for each line in LIST_FILE, get each line of LIST_FILE in array 'line'
6 - Copy the content of 'line' in 'compare' that will be used to check if it equal to the parameter 'path' (given to this function)
7 - Array 'line' may content a line break at the end so it will not be used to compare with the array 'path' (parameter transfered to this function)
	Array 'compare' will be used instead and line break is removed at the end
8 - Check if 'compare' is different from 'path'

	8.1 - Add 'line' aat the end of 'content' (only if 'compare' is different from 'path')
	
INFO - At the end of this process 'content' will contain all the lines of LIST_FILE without the line of the source to remove

	EXAMPLE :	
			
		Source to remove : 'sources/test2.txt'
		
		Original LIST_FILE :
		
			'sources/test1.txt
			sources/test2.txt
			sources/test3.txt'
			
		LIST_FILE after process :
		
			'sources/test1.txt
			sources/test3.txt'
			
9 - Open LIST_FILE and clean it from its content
10 - Copy 'content' in it

**/

int removeSourceInList(char* path)
{	
	char* c;
	
	FILE* file = NULL;
	
	file = fopen(LIST_FILE,"r");
	
	char content[getFileSize(file)];
	content[0] = 0;
	
	if(file != NULL)
	{
		char line[NAME_SIZE];
		char compare[NAME_SIZE];

		while(fgets(line,NAME_SIZE,file) != NULL)
		{
			strcpy(compare,line);
			if((c = strchr(compare,'\n')) != 0) *c = 0;
			
			if(strcmp(compare,path) != 0)
			{
				strcat(content,line);
			}
		}
		
		fclose(file);
	}
	
	else
	{
		CLEAR
		printf("\nERROR : cannot open \"%s\" !\n");
		printf("\nPress enter to exit...");
		getchar();
		exit(0);
	}
	
	file = fopen(LIST_FILE,"w");
	
	if(file != NULL)
	{
		if(content[strlen(content) - 1] == '\n') content[strlen(content) - 1] = '\0';
		if(content[strlen(content)] == '\n') content[strlen(content)] = '\0';
		fprintf(file,"%s",content);
		
		fclose(file);
	}
	
	else
	{
		CLEAR
		printf("\nERROR : cannot open \"%s\" !\n");
		printf("\nPress enter to exit...");
		getchar();
		exit(0);
	}
	
	return 1;
}