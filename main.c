#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "option.c"
int optionChoice();

struct USER
{
    char id[50];
    char password[50];
    struct USER *next1;
};
typedef struct USER user, *linklist1;

void login(linklist1 head);
void creat(linklist1 head);
void output1(linklist1 head);

int main() {
    FILE *fp;
    linklist1 head, p2, pre;
    head = (linklist1) malloc(sizeof(struct USER));
    head->next1 = NULL;
    pre = (linklist1) malloc(sizeof(struct USER));
    pre = head;
    if((fp = fopen("user.txt", "r")) == NULL){
        printf("dabukai\n");
        exit(0);
    }
    while (1){
        p2 = (linklist1) malloc(sizeof(struct USER));
        fscanf(fp, "%s %s", p2->id, p2->password);
        if(feof(fp)){
            break;
        }
        pre->next1 = p2;
        pre = p2;
    }
    pre->next1 = NULL;
    fclose(fp);

    int libraryOpen = 1;
    int option;
    while( libraryOpen ){
        printf("\n Please choose an option:\n 1) Register an account\n 2) Login\n 3) Search for books\n 4) Display all books\n 5) Quit\n   Option: ");
        option = optionChoice();
        if( option == 1 ) {
            printf("\n1111\n");
//            creat(head);
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


//int optionChoice(){
//    int option = -1;
//    char line[80];
//    fgets(line,80,stdin);
//    option = (int)atoi(line);
//    return option;
//}
