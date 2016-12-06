#include "functions.h"

/**

INFO -	This function gets the different elements of each line of a source file (word, definition and source) in three arrays

1 - Create an array for each element of the content passed in parameter

INFO -	Content passed in parameter looks like this :

		'title;definition;origin'
		
2 - First loop that get each character of the content while the character got is not a ';' and put them in array 'title'
	By this way 'title' will contain the first part before the ';'
3 - End the array to avoid unexpected characters
4 - Second loop that get each character between the first and the second ';' and put them in array 'definition'
5 - End the array to avoid unexpected characters
6 - Third loop that get the last part of the content between ';' and the end of 'content'
7 - 'content' may have a line break at end, it checks if there is one and replaces it by end of array
8 - Call "createWord.c" that will create a structure 'word' with the three arrays in parameters

**/

void getWord(primary* firstWord, char* content)
{
	/** Step 1 **/
	char title[TITLE];
	char definition[DEFINITION];
	char origin[ORIGIN];
	
	int i = 0, j = 0, k = 0, l = 0;
	
	/** Step 2 **/
	while(content[i] != ';')
	{
		title[j] = content[i];
		i++;
		j++;
	}
	
	/** Step 3 **/
	title[j] = '\0';
	
	i++;
	
	/** Step 4 **/
	while(content[i] != ';')
	{
		definition[k] = content[i];
		i++;
		k++;
	}
	
	/** Step 5 **/
	definition[k] = '\0';
	
	i++;
	
	/** Step 6 **/
	while(content[i] != '\0')
	{
		origin[l] = content[i];
		i++;
		l++;
	}
	
	/** Step 7 **/
	if(l > 0)
	{
		if(origin[l - 1] == '\n')
		{
			origin[l - 1] = '\0';
		}
		
		else
		{
			origin[l] = '\0';
		}	
	}
	
	/** Step 8 **/
	createWord(firstWord,title,definition,origin);
}