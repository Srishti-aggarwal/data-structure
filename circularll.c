#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

struct Node *getnew(int x){
    struct Node *getnew=(struct Node*)malloc(sizeof(struct Node));
    getnew->data=x;
    getnew->next=NULL;
    return getnew;
};

void insertbeg();
void insertend();
void printall();
void insertpos();

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
                int val;
                printf("\nEnter the value\n");
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
            default:
            break;
        }
    }

}
void insertbeg(int val){
    struct Node *temp=getnew(val);
    if(head==NULL){
    head=temp;
    temp->next=temp;
    }
    else{
    struct Node *last=head;
    while(last->next!=head){
        last=last->next;
    }
        temp->next=last->next;
        last->next=temp;
        head=temp;
    }
}
void insertend(int val){
    struct Node *temp=getnew(val);
    if(head==NULL){
        head=temp;
        temp->next=head;
    }
    else{
    struct Node *last=head;
    while(last->next!=head){
        last=last->next;
    }
    temp->next=head;
    last->next=temp;
    }
}
void printall(){
    struct Node *temp=head;
    if(head==NULL){
        printf("EMPTY LINKEDLIST\n");
        return;
    }
    printf("LINKLIST %d ",head->data);
    while(temp->next!=head){
        temp=temp->next;
        printf("%d ",temp->data);
    }
}
void insertpos(int x,int pos){
    struct Node *current=head;
    if(pos==1){
        insertbeg(x);
        return;
    }
    int i=0;
    while(i<pos-2){
        current=current->next;
        i++;
    }

    struct Node *temp=getnew(x);
    temp->next=current->next;
    current->next=temp;
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
    int i=0;
    while(current->next!=head){
            current=current->next;
            i++;
    }
    printf("Total nodes=%d\n",i);
}
void deletenode(int pos){
    struct Node *current=head;
    if(head==NULL){
        printf("EMPTY LINKEDLIST\n");
        return;
    }
    if(pos==1){
        current=current->next;
        head=current;
        return;
    }
    for(int i=0;i<pos-2;i++){
        current=current->next;
    }
    if(current->next->next==head){
        current->next=head;
        return;
    }
    current->next=current->next->next;
}
