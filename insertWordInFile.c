#include "functions.h"

/**

INFO -	Insert the new word with its definition and source in the corresponding source file

1 - Open the source file and prepare to write content at the end
2 - Check if there is already some content in the source file, if there is content, the function must insert a line break before writing the new word in the file
3 - If file is empty the function can write without inserting a line break before new word

**/

void insertWordInSource(char* sourcePath, char* word)
{
	FILE* file = NULL;
	
	/** Step 1 **/
	file = fopen(sourcePath,"a");
	
	if(file != NULL)
	{
		/** Step 2 **/
		if(getFileSize(file) > 0)
		{
			fprintf(file,"\n%s",word);
		}
		
		/** Step 3 **/
		else
		{
			fprintf(file,"%s",word);
		}
		
		fclose(file);
	}
	
	else
	{
		printf("\nERROR : cannot open \"%s\", word will not be saved at closing of the program !\n",sourcePath);
		printf("\nPress enter to continue...");
		getchar();
	}
}