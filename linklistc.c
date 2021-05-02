#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}Node;

struct Node *head;

void insertbeg();
void insertend();
void insertpos();
int randomnode();
int totalnode();
void deletenode();
void printall();

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
                insertbeg(head,val);
                break;
            }
            case 2:
            {
                int val;
                printf("\nEnter the value\n");
                scanf("%d",&val);
                insertend(head,val);
                break;
            }
            case 3:
            {
                int val;
                printf("\nEnter the value\n");
                scanf("%d",&val);
                int pos;
                printf("\nEnter the position\n");
                scanf("%d",&pos);
                insertpos(head,val,pos);
                break;
            }
            case 4:
            {
                int pos;
                printf("\nEnter the value\n");
                scanf("%d",&pos);
                int t=randomnode(head,pos);
                printf("\nData at %d position is %d\n",pos,t);
                break;
            }
            case 5:
            {
                int t=totalnode(head);
                printf("\nTotal number of nodes are %d\n",t);
                break;
            }
            case 6:
            {
                int pos;
                printf("\nEnter the value\n");
                scanf("%d",&pos);
                deletenode(head,pos);
                break;
            }
            case 7:
            {
                printall(head);
                break;
            }
            case 8:
                {
                    head=reversell(head);
                }
            default:
            break;
        }
    }

}
void insertbeg(struct Node *current,int ele){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=ele;
    temp->next=head;
    head=temp;
}
void insertend(struct Node *current,int ele){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=ele;
    while(current->next!=NULL){
        current=current->next;
    }
    temp->next=NULL;
    current->next=temp;
}
void insertpos(struct Node *current,int dt,int ele){
    for(int i=0;i<ele-2;i++){
        current=current->next;
    }
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=dt;
    temp->next=current->next;
    current->next=temp;
}
int randomnode(struct Node *current,int ele){
    for(int i=0;i<ele-1;i++){
        current=current->next;
    }
    return current->data;
}
int totalnode(struct Node *current){
    int c=1;
    while(current->next!=NULL){
        current=current->next;
        c++;
    }
    return c;
}
void deletenode(struct Node *current,int ele){
    for(int i=0;i<ele-2;i++)
    {
        current=current->next;
    }
    struct Node *next=current->next->next;
    free(current->next);
    current->next=next;
}
void printall(struct Node *current){
    printf("LINKLIST %d ",current->data);
    while(current->next!=NULL){
        current=current->next;
        printf("%d ",current->data);
    }
}

void reversell(struct Node *head){
    struct Node *prev,*current,*next;
    prev=NULL;
    current=head;
    while(next!=NULL){
        while(current!=NULL)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
}
void recur(struct Node* current){
    while(current->next!=NULL)
    {
        current=current->next;
    }
    recur(current->next);
    struct Node*temp=current->next;
    temp->next=current;
    current->next=NULL;
}
