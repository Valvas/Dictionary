#include "functions.h"

/**

INFO -	Get the name of the file to correct and call "readDocument.c" to read and correct file

1 - Get the path of the documents folder -> DOCUMENT_FOLDER_PATH (constant defined in "functions.h")
2 - Get user's entry that must be the name of the document to read and correct
3 - Concatenate path with file name

	EXAMPLE : path -> "doc/", file -> "test.txt", concatenation -> "doc/test.txt"
	
4 - Call "readDocument.c" that will read the file and correct words by using the dictionary

**/

void correctDocument(primary* firstWord)
{
	char document[NAME_SIZE];
	char path[NAME_SIZE];
	
	/** Step 1 **/
	strcpy(path,DOCUMENT_FOLDER_PATH);
	
	CLEAR
	
	printf("WARNING - All documents must be placed in folder \"%s\" from root directory !\n",path);
	printf("\nEnter the name of your document (with extension and without path) : ");
	
	/** Step 2 **/
	entry(document,NAME_SIZE);
	
	CLEAR
	
	/** Step 3 **/
	strcat(path,document);
	
	/** Step 4 **/
	readDocument(firstWord,path);
}