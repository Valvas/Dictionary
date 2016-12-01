#include "functions.h"

int addSourceInList(char* name)
{
    FILE* file = NULL;

    file = fopen(LIST_FILE,"a");

    if(file != NULL)
    {
        fprintf(file,"\n%s",name);
        fclose(file);
		
		printf("\nSUCCESS : source file added in \"%s\" !\n",LIST_FILE);
		printf("\nPress enter to continue...");
		getchar();
		return 1;
    }

    else
    {
        CLEAR
        printf("\nERROR : cannot open \"list.info\" !\n");
        printf("\nPress enter to continue...");
        getchar();
		return 0;
    }
}
