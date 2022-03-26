#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

#include "do_book.h"
#include "do_book.c"

void output_user(linklist1 head) //Put the user's account number and password into the file
{
    linklist1 p=head->next1;
    FILE *fp = fopen("user.txt", "w");
    if(fp==NULL){
        printf("Can not open the file.\n");
        exit(0);
    }
    while (p){
        fprintf(fp, "%s %s\n", p->username, p->password);
        p=p->next1;
    }
    fclose(fp);
}

void regi(linklist1 head) //User Registration (linked list)
{
    linklist1 last = head, p;
    int check = 0;//Check whether the username is duplicated.
    p=(linklist1) malloc(sizeof(user));
    printf("Please enter a username:");
    scanf("%s", p->username);
    getchar();
    while (last->next1)
    {
        last=last->next1;
        if(strcmp(last->username, p->username) == 0){
            printf("Sorry, registration unsuccessful, the username you entered already exists.\n");
            check = 1;
            break;
        }
    }
    if(check == 0){
        printf("Please enter a password:");
        scanf("%s", p->password);
        getchar();
        p->next1 = last->next1;
        last->next1 = p;
        printf("Registered library account successfully!\n");
    }
}

void login(linklist1 head) //User login.
{
    linklist1 last = head, p;
    int check = 0;
    p=(linklist1) malloc(sizeof(user));
    printf("Please enter a username:");
    scanf("%s", p->username);
    getchar();
    while (last->next1){
        last = last->next1;
        if(strcmp(last->username, p->username) == 0){
            check = 1;
            break;
        }
    }
    if(check==0){
        printf("The user does not exist.\n");
    } else{
        printf("Please enter a password:");
        scanf("%s", p->password);
        getchar();
        if(strcmp(last->password, p->password) == 0){
            printf("\n(logged in as: %s)", last->username);
//            FILE *fp;
//            if((fp = fopen("books.txt", "r")) == NULL){
//                printf("Can not open the file.\n");
//                exit(0);
//            }
//            store_books(fp);
//            fclose(fp);
            books();
        } else{
            printf("Password is wrong.\n");
        }
    }
}

//int store_books(FILE *file)
//{
//    int option;
//    int userOpen = 1;
//    FILE *fp;
//    linklist head, p2, last;
//    head = (linklist) malloc(sizeof(Book));
//    head->next = NULL;
//    last = (linklist) malloc(sizeof(Book));
//    last = head;
//    if((fp = fopen(file, "r")) == NULL){
//        printf("Can not open the file.\n");
//        exit(0);
//    }
//    while (1){
//        p2 = (linklist) malloc(sizeof(Book));
//        p2->authors=(char*)malloc(100*sizeof(char));
//        p2->title=(char*)malloc(100*sizeof(char));
//        fscanf(fp, "%d %s %s %d %d", &p2->id, p2->title, p2->authors, &p2->year, &p2->copies);//problem
////        printf("%d %s %s %d %d", p2->id, p2->title, p2->authors, p2->year, p2->copies);
//        if(feof(fp)){
//            break;
//        }
//        last->next = p2;
//        last = p2;
//    }
//    last->next = NULL;
//    fclose(fp);
//    while (userOpen){
//        printf("\n Please choose an option:\n 1) Add a book\n 2) Remove a book\n 3) Search for books\n 4) Display all books\n 5) Log out\n   Option: ");
//        option = optionChoice();
//        if(option == 1){
//            printf("1");
//        }
//        else if(option == 2){
//            printf("2");
//        }
//        else if(option == 3){
//            printf("3");
//        }
//        else if(option == 4){
//            all_books();
//            break;
//        }
//        else if(option == 5){
//            printf("back\n");
//            break;
//        } else{
//            printf("Error enter.\n");
//        }
//    }
//    return 0;
//}

void books()
{
    int option;
    int userOpen = 1;
    FILE *fp;
    linklist head, p2, last;
    head = (linklist) malloc(sizeof(Book));
    head->next = NULL;
    last = (linklist) malloc(sizeof(Book));
    last = head;
    if((fp = fopen("books.txt", "r")) == NULL){
        printf("Can not open the file.\n");
        exit(0);
    }
    while (1){
        p2 = (linklist) malloc(sizeof(Book));
        p2->authors=(char*)malloc(100*sizeof(char));
        p2->title=(char*)malloc(100*sizeof(char));
        fscanf(fp, "%d %s %s %d %d", &p2->id, p2->title, p2->authors, &p2->year, &p2->copies);
        if(feof(fp)){
            break;
        }
        last->next = p2;
        last = p2;
    }
    last->next = NULL;
    fclose(fp);
    while (userOpen){
        printf("\n Please choose an option:\n 1) Add a book\n 2) Remove a book\n 3) Search for books\n 4) Display all books\n 5) Log out\n   Option: ");
        option = optionChoice();
        if(option == 1){
            printf("1");
        }
        else if(option == 2){
            printf("2");
        }
        else if(option == 3){
            search(head);
        }
        else if(option == 4){
            all_books();
        }
        else if(option == 5){
            break;
        } else{
            printf("Error enter.\n");
        }
    }
}

void all_books()
{
    FILE *fp;
    linklist head, p2, last;
    head = (linklist) malloc(sizeof(Book));
    head->next = NULL;
    last = (linklist) malloc(sizeof(Book));
    last = head;
    if((fp = fopen("books.txt", "r")) == NULL){
        printf("Can not open the file.\n");
        exit(0);
    }
    printf("Id     Title          Authors          year     copies\n");
    while (1){
        p2 = (linklist) malloc(sizeof(Book));
        p2->authors=(char*)malloc(100*sizeof(char));
        p2->title=(char*)malloc(100*sizeof(char));
        fscanf(fp, "%d %s %s %d %d", &p2->id, p2->title, p2->authors, &p2->year, &p2->copies);//problem
        printf(" %-6d %-14s %-16s %-8d %-11d\n", p2->id, p2->title, p2->authors, p2->year, p2->copies);
        if(feof(fp)){
            break;
        }
        last->next = p2;
        last = p2;
    }
    last->next = NULL;
    fclose(fp);
}

//void output_books(linklist head){
//    linklist p = head->next;
//    FILE *fp;
//    fp = fopen("books.txt", "w");
//    if(fp == NULL){
//        printf("Can not open the file.\n");
//        exit(0);
//    }
//    while (p){
//        fprintf(fp,"%d %s %s %d %d\n", &p->id, p->title, p->authors, &p->year, &p->copies);
//    }
//} load the file.


