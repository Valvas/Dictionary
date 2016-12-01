#include "functions.h"

//REMOVE BLANKS AND LINE BREAKS AT THE BEGINNING OF THE FILE
void beginning_format(char* content, int* size)
{
    int k = 0;

    for(k = 0; k < *size; k++)
    {
        if(content[k + 1])
        {
            content[k] = content[k + 1];
        }
    }

    *size -= 1;
}

//REMOVE BLANKS AFTER A LINE BREAK
void remove_blank_after_line_break(char* content, int* size, int i)
{
    int j = i + 1;
    int k = 0;

    for(k = j; k < *size; k++)
    {
        if(content[j + 1])
        {
            content[j] = content[j + 1];
            j++;
        }
    }

    *size -= 1;
}

//REMOVE BLANKS BEFORE A LINE BREAK
void remove_blank_before_line_break(char* content, int* size, int i)
{
    int j = 1, k = 0;

    while(content[i - j] == ' ')
    {
        for(k = (i - j); k < *size; k++)
        {
            content[k] = content[k + 1];
        }

        j++;

        *size -= 1;
    }
}

//CHECK IF THERE ARE NOT MORE OR LESS THAN THREE ARGUMENTS ON EACH LINE
int check_number_of_arguments(char* content, int* size)
{
    int i = 0, count = 0;

    for(i = 0; i < *size; i++)
    {
        if(content[i] == ';')
        {
            count++;
        }

        if(content[i] == '\n' || (i + 1) == *size)
        {
            if(count != 2)
            {
                return 1;
            }

            count = 0;
        }
    }

    return 0;
}

//PRINT NEW CONTENT IN SOURCE FILE
void print_content_source_file(char* name, char* content)
{
    FILE* file = NULL;

    file = fopen(name,"w");

    if(file != NULL)
    {
        fprintf(file,content);

        fclose(file);
    }

    else
    {
        printf("\nERROR : could not format \"%s\" !",name);
    }
}

//SET CONTENT TO LOWERCASE AND FIRST LETTER OF DEFINITION TO UPPERCASE
void set_content_to_lowercase(char* content, int* size)
{
    int i = 0, count = 0;

    for(i = 0; i < *size; i++)
    {
        if(content[i] == ';' && count == 0)
        {
            count++;
            i++;

            if(content[i] > 96 && content[i] < 123)
            {
                content[i] -= 32;
            }

            i++;
        }

        if(content[i] > 64 && content[i] < 91)
        {
            content[i] += 32;
        }

        if(content[i] == '\n' || (i + 1) == *size)
        {
            count = 0;
        }
    }
}

//REMOVE BLANKS AT THE END OF THE FILE
void remove_blank_at_end(char* content, int* size)
{
    int i = 0;

    while(content[(*size - 1) - i] == '\n')
    {
        i++;
        *size -= 1;
    }
}
