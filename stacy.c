#include<stdio.h>
#include<stdlib.h>
#define MAX_INT 2

struct stack{
    int top;
    int size;
    int *array;
};
struct stack *create(){
    struct stack *s=malloc(sizeof(struct stack));
    s->size=MAX_INT;
    s->top=-1;
    return s;
};
void dyn(struct stack *s){

    s->size*=2;
    s->array=realloc(s->array,s->size*sizeof(int));

}
int Isempty(struct stack *s){
    if(s->top==-1)
    {
        printf("\nStack Underflow\tStack is empty");
        return 1;
    }
    else
    {
        return 0;
    }
}
int stacktop(struct stack *s){
      return s->array[s->top];
}
void push(struct stack *s,int e){

    s->array[++s->top]=e;
}
void pop(struct stack *s){
    if(Isempty(s)!=1)
    s->top--;
}
void Print(struct stack *s){
    if(s->top==-1)
        printf("No element to show.Stack is empty.");
    else
    {
    for(int i=s->top;i>=0;i--)
    {
        printf("%d ",s->array[i]);
    }
    }
}
int main()
{
    struct stack *s=create(100);
    while(1)
    {
    printf("\n\n1.push\t 2.pop\t 3.top\t 4.empty?\t 5.print\t 6.Clear and exit\n");
    int ch;
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter the element:");
        int ele;
        scanf("%d",&ele);
        if(s->size-1==s->top){
        void dyn(s);
        }
        push(s,ele);
        break;
    case 2:
        pop(s);
        break;
    case 3:
         if(Isempty(s)==0)
            printf("%d",stacktop(s));
        break;
    case 4:
        if(Isempty(s)==0)
        printf("No,Stack isnt empty.");
        break;
    case 5:
        Print(s);
        break;
    case 6:
        free(s);
        exit(0);
    default:
        printf("\nWrong input");
        break;
    }
    }
    return 0;
}

