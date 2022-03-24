#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            printf("yes");
        } else{
            printf("Password is wrong.\n");
        }
    }
}

