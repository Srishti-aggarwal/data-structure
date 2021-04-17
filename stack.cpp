#include<iostream>
#define MAX_INT 3
using namespace std;

class stack{
    private:
    int top;
    int array[MAX_INT];
    public:
    stack()
    {
        top=-1;
    }
    bool Isempty(){
        if(top==-1)
        return 1;
        else
        return 0;
    }
    bool Isfull(){
        if(top==MAX_INT-1)
        return 1;
        else
        return 0;
    }
    void stackstop(){
        if(Isempty()==1)
        cout<<"Stack is empty"<<endl;
        else
        cout<<array[top]<<"\n";
    }
    void push(int ele){
        if(Isfull()==1)
        cout<<"Stack Overflow\n";
        else
        array[++top]=ele;
    }
    void pop(){
        if(Isempty()==1)
        cout<<"Stack Underflow\n";
        else
        top--;
    }
    void Print(){
        if(Isempty()==1)
        cout<<"Stack is empty,nothing to show\n";
        else
        {
            for(int i=top;i>=0;i--)
            cout<<array[i]<<" ";
        }
    }
};
int main(){
    stack s;
    while(1)
    {
    printf("\n1.push\n2.pop\n3.top\n4.empty?\n5.full?\n6.print\n7.Clear and exit\n");
    char ch;
    cin>>ch;
    switch (ch)
    {
    case '1':
    cout<<"Enter the element:\n";
    int e;
    cin>>e;
    s.push(e);
    break;
    case '2': s.pop();
    break;
    case '3': s.stackstop();
    break;
    case '4':
    if(s.Isempty()==1)
    cout<<"Stack is empty\n"<<endl;
    else
    cout<<"Stack is not empty\n"<<endl;
    break;
    case '5':
    if(s.Isfull()==1)
    cout<<"Stack is full"<<endl;
    else
    cout<<"Stack is not full"<<endl;
    break;
    case '6': s.Print();
    break;
    case '7':
        exit(0);
    default:
    cout<<"wrong input";
    break;
    }
    }
    return 0;
}
