#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "option.h"
#include "option.c"

void search(linklist head)
{
    int option;
    int libraryOpen = 1;
    while (libraryOpen){
        printf("Loading search menu...\n");
        printf("\nPlease choose an option:\n");
        printf("1) Find books by title\n");
        printf("2) Find books by author\n");
        printf("3) Find books by year\n");
        printf("4) Return to previous menu\n");
        option = optionChoice();
        if(option == 1){
            printf("title");
        }
        else if(option == 2){
            printf("author");
        }
        else if(option == 3){
            printf("year");
        }
        else if(option == 4){
            break;
        }
    }
}


