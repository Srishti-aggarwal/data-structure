#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

node *h[10]={NULL};

void sortedinsert(int val){
    int x=val%10;
    node *c=(node *)malloc(sizeof(node));
    c->data=val;
    node *p=h[x],*q=h[x];
    c->next=NULL;
    if(h[x]==NULL)
    h[x]=c;
    else{
        while(q->data<x){
            p=q;
            q=q->next;
        }
        c->next=p->next;
        p->next=c;
    }
}

node* search(int x){
    node *c=h[x%10];
    while(c!=NULL && c->data!=x){
        c=c->next;
    }
    return c;
}

void deletekey(int key){
    node *head=h[key%10];
    node *prev, *cur;
    while(head->data==key && head!=NULL){
        prev=head;
        head=head->next;
        delete(prev);
        return;
    }
    prev=NULL;
    cur=head;
    while(cur!=NULL){
        if(cur->data==key){
        if(prev!=NULL)
        prev->next=cur->next;
        delete(cur);
        return;
        }
    prev=cur;
    cur=cur->next;
    }
}

void printhash(){
    for(int i=0;i<10;i++){
        node *temp=h[i];
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

int main(){
    int val,key,i=0;
    while(i<10){
        cin>>val;
        sortedinsert(val);
        i++;
    }
    cin>>key;
    node *temp;
    //temp=search(key);
    deletekey(key);
    printhash();
    //cout<<"output"<<temp->data;
    return 0;
}