#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node *prev;
struct Node *next;
}Node;

struct Node *head;

struct Node *getnn(int x){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
};

void insertbeg();
void insertend();
void printall();
void insertpos();
void randomnode();
void deletenode();
void reversell();

int main(){
    head=NULL;
    while(1){
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insertpos\n4.random node\n5.total nodes\n6.Delete node\n7.Print all nodes\n8.reverse the linked list\n");
        int choice;
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                printf("\nEnter the value\n");
                int val;
                scanf("%d",&val);
                insertbeg(val);
                break;
            }
            case 2:
            {
                int val;
                printf("\nEnter the value\n");
                scanf("%d",&val);
                insertend(val);
                break;
            }
            case 3:
            {
                int val;
                printf("\nEnter the value\n");
                scanf("%d",&val);
                printf("\nEnter the position\n");
                int id;
                scanf("%d",&id);
                insertpos(val,id);
                break;
            }
            case 4:
            {
                  int val;
                  printf("Enter the position:");
                  scanf("%d",&val);
                  randomnode(val);
                  break;
            }
            case 5:
            {
                totalnode();
                break;
            }
            case 6:
            {
                int val;
                printf("Enter the position:");
                scanf("%d",&val);
                deletenode(val);
                break;
            }
            case 7:
            {
                printall();
                break;
            }
            case 8:
            {
                reversell();
                break;
            }
            default:
                exit(0);
        }
    }
    return 0;

}

void insertbeg(int ele){
    struct Node *temp=getnn(ele);
    if(head==NULL){
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}
void insertend(int x){
    struct Node *temp=getnn(x);
    if(head==NULL){
        head=temp;
        return;
    }
    struct Node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;
    temp->prev=current;
}
void insertpos(int x,int pos){
    struct Node *current=head;
    struct Node *temp=getnn(x);
    if(pos==1){
        insertbeg(x);
        return;
    }
    int i=0;
    while(i<pos-2){
        current=current->next;
        i++;
    }

    temp->next=current->next;
    current->next=temp;
    temp->prev=current;
    if(current->next!=NULL){
    current->next->prev=temp;}
}
void randomnode(int x){
    struct Node *current=head;
    if(head==NULL){
        printf("EMPTY LINKEDLIST\n");
        return;
    }
    for(int i=0;i<x-1;i++){
        current=current->next;
    }
    printf("Data at %d position is %d",x,current->data);
}
void totalnode(){
    struct Node *current=head;
    int c=0;
    while(current!=NULL){
        current=current->next;
        c++;
    }
    printf("Total number of nodes=%d",c);
}
void deletenode(int x){
    struct Node *current=head;
    if(head==NULL){
        printf("EMPTY LINKEDLIST\n");
        return;
    }
    if(x==1){
        current=current->next;
        head=current;
        return;
    }
    for(int i=0;i<x-2;i++){
        current=current->next;
    }
    current->next=current->next->next;
    current->next->prev=current;
}
void printall(){
    struct Node *temp=head;
    if(head==NULL){
        printf("EMPTY LINKEDLIST\n");
        return;
    }
    printf("LINKLIST ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        }
    }
void reversell(){
    struct Node *current=head;
    if(head==NULL){
        printf("EMPTY LINKEDLIST\n");
        return;
    }
    while(current->next!=NULL){
        current=current->next;
    }
    head=current;
    while(current->prev!=NULL){
        printf("%d ",current->data);
        current=current->prev;
    }
}
void reverselist(){
    struct Node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    head=current;
    current->next=current->prev;
    current->prev=NULL;
    struct Node *temp=current;
    while(current->next!=NULL){
        current=current->next;
        current->next=current->prev;
        current->prev=temp;
        temp=current;
    }
    return head;
}


