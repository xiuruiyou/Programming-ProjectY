#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "option.c"
int optionChoice();

struct USER
{
    char username[50];
    char password[50];
    struct USER *next1;
};
typedef struct USER user, *linklist1;

void login(linklist1 head);
void regi(linklist1 head);
void output_user(linklist1 head);

int main() {
    FILE *fp;
    linklist1 head, p2, last;
    head = (linklist1) malloc(sizeof(struct USER));
    head->next1 = NULL;
    last = (linklist1) malloc(sizeof(struct USER));
    last = head;
    if((fp = fopen("user.txt", "r")) == NULL){
        printf("Can not open the file.\n");
        exit(0);
    }
    while (1){
        p2 = (linklist1) malloc(sizeof(struct USER));
        fscanf(fp, "%s %s", p2->username, p2->password);
        if(feof(fp)){
            break;
        }
        last->next1 = p2;
        last = p2;
    }
    last->next1 = NULL;
    fclose(fp);

    int libraryOpen = 1;
    int option;
    while( libraryOpen ){
        printf("\n Please choose an option:\n 1) Register an account\n 2) Login\n 3) Search for books\n 4) Display all books\n 5) Quit\n   Option: ");
        option = optionChoice();
        if( option == 1 ) {
            regi(head);
            output_user(head);
        }
        else if( option == 2 ) {
            printf("\n2222\n");
//            login(head);
        }
        else if( option == 3 ) {
            printf("\n3333\n");
        }
        else if( option == 4 ) {
            printf("\n4444\n");
        }
        else if( option == 5 ) {
            libraryOpen = 0;
            printf("\nClosing\n");
            exit(0);
        }
        else
            printf("\nSorry, the option you entered was invalid, please try again.\n");
    }
    return 0;
}

void output_user(linklist1 head)
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

void regi(linklist1 head)
{
    linklist1 last = head, p;
    int flag = 0;
    p=(linklist1) malloc(sizeof(struct USER));
    printf("Please enter a username:");
    scanf("%s", p->username);
    getchar();
    while (last->next1)
    {
        last=last->next1;
        if(strcmp(last->username, p->username) == 0){
            printf("Sorry, registration unsuccessful, the username you entered already exists.\n");
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Please enter a password:");
        scanf("%s", p->password);
        getchar();
        p->next1 = last->next1;
        last->next1 = p;
        printf("Registered library account successfully!\n");
    }
}


