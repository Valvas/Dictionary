#include "functions.h"

void manageSources(head* listHead, primary* firstWord)
{
    short run = 1, size = 3;
    long choice = 0;
    int count = 1;

    while(run)
    {
        while(choice < 1 || choice > 5)
        {
            CLEAR

            printf("\n");
            printf("+==================================+\n");
            printf("|          Manage Sources          |\n");
            printf("+==================================+\n");

            printf("\n1. Add new source");
			printf("\n2. Create source");
            printf("\n3. Remove source");
            printf("\n4. Show sources");
            printf("\n5. Back");
            printf("\n\nEnter a value (1 to 5) : ");

            choice = integer(size);

            switch(choice)
            {
                case ADD_SOURCE :  addSource(listHead,firstWord); choice = 0; break;
				case CREATE_SOURCE : createSource(listHead,firstWord); choice = 0; break;
					
                case REMOVE_SOURCE : 
				
					if(listHead->sourceTarget) deleteSource(listHead);
					
					else
					{
						CLEAR
						
						printf("\nERROR : There are no sources yet !\n");
						printf("\nPress enter to continue...");
						getchar();
					}
					
					choice = 0; 
					break;
					
                case SHOW_SOURCES :

                    CLEAR
                    printf("==========================================\n");
					if(listHead->sourceTarget) showSources(listHead->sourceTarget,&count);
					else printf("\nNo sources yet !\n\n");     
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
