#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "option.c"
#define MAX 128
#define RECORD_FILE "user.txt"
#define RECORD_FILE2 "books.txt"

int load_books(FILE* file)
{
    FILE *fp;
    char buf[100];
    linklist head, p2, last;
    head = (linklist) malloc(sizeof(Book));
    head->next = NULL;
    last = head;
    if((fp = fopen(file, "r")) == NULL){
        printf("Can not open the file.\n");
        return -1;
    }
    printf("Id      Title                     Authors              year       copies\n");
    while (1){
        p2 = (linklist) malloc(sizeof(Book));
        p2->authors=(char*)malloc(100*sizeof(char));
        p2->title=(char*)malloc(100*sizeof(char));
        fgets(buf, MAX, fp);
        sscanf(buf, "%d\n", &p2->id);
        fgets(buf, MAX, fp);
        sscanf(buf, "%[^\n]s\n", p2->title);
        fgets(buf, MAX, fp);
        sscanf(buf, "%[^\n]s\n", p2->authors);
        fgets(buf, MAX, fp);
        sscanf(buf, "%d\n", &p2->year);
        fgets(buf, MAX, fp);
        sscanf(buf, "%d\n", &p2->copies);
//        fscanf(fp, "%d %s %s %d %d\n", &p2->id, p2->title, p2->authors, &p2->year, &p2->copies);
        printf(" %-7d %-25s %-20s %-10d %-6d\n", p2->id, p2->title, p2->authors, p2->year, p2->copies);
        if(feof(fp)){
            break;
        }
        last->next = p2;
        last = p2;
    }
    last->next = NULL;
    fclose(fp);
    return 0;
}


int store_books(linklist head)
{
//    linklist p, head;
//    p = head->next;
    linklist p = head->next;
    FILE *fp;
    fp = fopen("books.txt", "w");
    if(fp == NULL){
        printf("Can not open the file.\n");
        return -1;
    }
    while (p){
        fprintf(fp,"%d\n%s\n%s\n%d\n%d\n", p->id, p->title, p->authors, p->year, p->copies);
        p = p->next;
    }
    fclose(fp);
    return 0;
}


int add_book(linklist head)
{
    linklist last = head, p;
    int n = 0;
    p = (linklist) malloc(sizeof(Book));
//    printf("Enter the title of the book you wish to add: ");
//    gets(p->title);
//    getchar();
//    printf("Enter the author that the book you wish to add was released: ");
//    gets(p->authors);
//    printf("Enter the year of the book you wish to add: ");
//    gets(&p->year);
//    printf("Enter the number of copies of the book that you wish to add: ");
//    gets(&p->copies);
    printf("Please enter the title, authors, year and copies:\n");
    scanf("%s%s%d%d", p->title, p->authors, &p->year, &p->copies);
    getchar();
    while (last->next){
        last = last->next;
        if(strcmp(last->title, p->title) == 0){
            printf("The book already exists.\n");
            n = 1;
            break;
        }
    }
    if(n == 0){
        p->next = last->next;
        last->next = p;
//        last->id = p->id + 1;
        printf("Book was successfully added!\n");
    }
    return 0;
}

void search()
{
    //for find
    char TITLE[100];
    char AUTHOR[100];
    unsigned int YEAR;

    char buf[100];
    FILE *fp;
    linklist head, p2, last;
    head = (linklist) malloc(sizeof(Book));
    head->next = NULL;
    last = head;
    if ((fp = fopen(RECORD_FILE2, "r")) == NULL) {
        printf("Can not open the file.\n");
        exit(0);
    }
    while (1) {
        p2 = (linklist) malloc(sizeof(Book));
        p2->authors = (char *) malloc(100 * sizeof(char));
        p2->title = (char *) malloc(100 * sizeof(char));
        fgets(buf, MAX, fp);
        sscanf(buf, "%d\n", &p2->id);
        fgets(buf, MAX, fp);
        sscanf(buf, "%[^\n]s\n", p2->title);
        printf("%s\n", p2->title);
        fgets(buf, MAX, fp);
        sscanf(buf, "%[^\n]s\n", p2->authors);
        fgets(buf, MAX, fp);
        sscanf(buf, "%d\n", &p2->year);
        fgets(buf, MAX, fp);
        sscanf(buf, "%d\n", &p2->copies);
        if (feof(fp)) {
            break;
        }
        last->next = p2;
        last = p2;
    }
    last->next = NULL;
    fclose(fp);

    int option;
    int libraryOpen = 1;
    printf("\nLoading search menu...\n");
    while (libraryOpen){
        printf("\nPlease choose an option:\n");
        printf("1) Find books by title\n");
        printf("2) Find books by author\n");
        printf("3) Find books by year\n");
        printf("4) Return to previous menu\n");
        printf("Option: ");
        option = optionChoice();
        if(option == 1){
            printf("Please enter title:");
            scanf("%[^\n]s", TITLE);
            find_book_by_title(TITLE, head);
        }
        else if(option == 2){
            printf("Please enter author:");
            scanf("%[^\n]s", AUTHOR);
            find_book_by_author(AUTHOR, head);
        }
        else if(option == 3){
            printf("Please enter year:");
            scanf("%d", &YEAR);
            find_book_by_year(YEAR, head);
        }
        else if(option == 4){
            break;
        } else{
            printf("Invalid inputs.\n");
        }
    }
}

BookList find_book_by_title (const char *title, linklist head)
{
    linklist p = head;
    BookList list1;
    int n = 0;
    getchar();
    while (p){
//        printf("%s %s\n", p->title, title);
        if(strcmp(p->title, title) == 0){
            n = 1;
            break;
        }
        p = p->next;
    }
    if(n == 0)
    {
        printf("No result.\n");
    } else{
        printf("Id      Title                     Authors              year       copies\n");
        n = 0;
        while (p){
            if(strcmp(p->title, title) == 0){
                printf(" %-7d %-25s %-20s %-10d %-6d\n", p->id, p->title, p->authors, p->year, p->copies);
                n += 1;
            }
            p = p->next;
        }
    }
    list1.length = n;
    list1.list->title = title;
    return list1;
}

BookList find_book_by_author (const char *author, linklist head)
{
    linklist p = head;
    BookList list1;
    int n = 0;
    getchar();
    while (p->next!=NULL){
        p = p->next;
        printf("%s %s\n", p->authors, author);
        if(strcmp(p->authors, author) == 0){
            n = 1;
            break;
        }
    }
    if(n == 0)
    {
        printf("No result.\n");
    } else{
        printf("Id      Title                     Authors              year       copies\n");
        n = 0;
        while (p){
            if(strcmp(p->authors, author) == 0){
                printf(" %-7d %-25s %-20s %-10d %-6d\n", p->id, p->title, p->authors, p->year, p->copies);
                n += 1;
            }
            p = p->next;
        }
    }
    list1.length = n;
    list1.list->authors = author;
    return list1;
}

BookList find_book_by_year (unsigned int year, linklist head)
{
    linklist p = head;
    BookList list1;
    int n = 0;
    getchar();
    while (p->next!=NULL){
        p = p->next;
        if(p->year == year){
            n = 1;
            break;
        }
    }
    if(n == 0)
    {
        printf("No result.\n");
    } else{
        printf("Id      Title                     Authors              year       copies\n");
        n = 0;
        while (p){
            if(p->year == year){
                printf(" %-7d %-25s %-20s %-10d %-6d\n", p->id, p->title, p->authors, p->year, p->copies);
                n += 1;
            }
            p = p->next;
        }
    }
    list1.length = n;
    list1.list->year = year;
    return list1;
}
