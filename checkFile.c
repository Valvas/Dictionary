#include "functions.h"

/**

INFO - This function calls other functions all in format_source.c

1 - Try to open file, if file can not be opened return 0, if it can be opened go to step 2
2 - Get the number of characters in source file by using file_size.c
3 - Put all characters in a char* named 'content' in order to apply modifications directly on 'content' before replacing source file content by 'content'
4 - Read each character in source file by using a loop :

    . If each line's first character is a ';' --> return 0
    . If there are two ';' in a row ---> return 0
    . Remove all blanks in source file

5 - Check the number of arguments for each line in source file :

    . If there are less or more than two arguments on a line --> return 0 (arguments are separated by ';' ---> example : "word;definition;source")

6 - Put all characters in lowercase and first letter of argument 'definition' in uppercase
7 - Replace source file content by 'content'

**/

int checkFile(char* name)
{
    /** Step 1 **/
    FILE* source = NULL;

    int c = 0, size = 0, i = 0, tooMuchArguments = 0;

    source = fopen(name,"r");

    if(source != NULL)
    {
        /** Step 2 **/
        size = getFileSize(source);
        char content[size];

        /** Step 3 **/
        for(i = 0; i < size; i++)
        {
            c = fgetc(source);
            content[i] = c;
        }

        /** Step 4 **/
        for(i = 0; i < size; i++)
        {
            if(content[i + 1])
            {
                /** REMOVE BLANKS AND LINE BREAKS AT THE BEGINNING OF THE FILE **/
                while(content[0] == '\n' || content[0] == ' ')
                {
                    beginningFormat(content,&size);
                }

                /** CHECK IF LINE DOES NOT START WITH A ';' AND IF THERE ARE NOT TWO ';' IN A ROW **/
                if((content[0] == ';') || ((content[i] == '\n') && (content[i + 1] == ';')) || (content[i] == ';' && content[i + 1] == ';'))
                {
                    printf("\nERROR : bad format in \"%s\" !\n",name);
					printf("\nPress enter to continue...");
					getchar();
                    return 0;
                }

                /** REMOVE BLANKS AFTER A LINE BREAK **/
                while(content[i] == '\n' && (content[i + 1] == '\n' || content[i + 1] == ' '))
                {
                    removeBlankAfterLineBreak(content,&size,i);
                }

                /** REMOVE BLANKS BEFORE A LINE BREAK **/
                if(content[i] == '\n')
                {
                    removeBlankBeforeLineBreak(content,&size,i);
                }
            }
        }

        /** REMOVE BLANKS AT END OF THE FILE **/
        removeBlankAtEnd(content,&size);

        content[size] = '\0'; /** END CONTENT AT NEW SIZE DEFINED AFTER REMOVING ALL BLANKS **/

        /** Step 5 **/
        if((tooMuchArguments = checkNumberOfArguments(content,&size)))
        {
            printf("\nERROR : too much arguments in \"%s\" !\n",name);
			printf("\nPress enter to continue...");
			getchar();
            return 0;
        }

        /** Step 6 **/
        setContentToLowercase(content,&size);

        /** Step 7 **/
        printContentSourceFile(name,content);

        fclose(source);
        return 1;
    }

    /** IF FILE CAN NOT BE OPENED **/
    else
    {
        printf("\nERROR : cannot open \"%s\" !\n",name);
        printf("\nPress enter to continue...");
        getchar();
		return 0;
    }
}
