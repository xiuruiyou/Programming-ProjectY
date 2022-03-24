#ifndef CWK1_USER_H
#define CWK1_USER_H
//struct USER
//{
//    char username[50];
//    char password[50];
//    struct USER *next1;
//};
//typedef struct USER user, *linklist1;

typedef struct _User
{
    char username[50];
    char password[50];
    struct _User *next1;
}user, *linklist1;


void login(linklist1 head);
void regi(linklist1 head);
void output_user(linklist1 head);
#endif //CWK1_USER_H
