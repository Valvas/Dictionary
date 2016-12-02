#include "functions.h"

void manageSources(source* firstSource)
{
    short run = 1, size = 3;
    long choice = 0;
    int count = 1;

    while(run)
    {
        while(choice < 1 || choice > 4)
        {
            CLEAR

            printf("\n");
            printf("+==================================+\n");
            printf("|          Manage Sources          |\n");
            printf("+==================================+\n");

            printf("\n1. Add new source");
            printf("\n2. Remove source");
            printf("\n3. Show sources");
            printf("\n4. Back");
            printf("\n\nEnter a value (1 to 4) : ");

            choice = integer(size);

            switch(choice)
            {
                case ADD_SOURCE :  addSource(firstSource); choice = 0; break;
                case REMOVE_SOURCE : deleteSource(firstSource); choice = 0; break;
                case SHOW_SOURCES :

                    CLEAR
                    printf("==========================================\n");
                    showSources(firstSource,&count);
                    printf("==========================================\n");
                    printf("\nPress enter to continue...");
                    getchar();
					count = 1;
                    choice = 0;
                    break;

                case BACK_MENU : run = 0; break;
            }
        }
    }
}
