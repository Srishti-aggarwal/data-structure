#include<iostream>
using namespace std;

void insertkey(int h[],int key){
    int x=key%10;
    int i=0;
    while(h[x]!=0){
        x=(x+i)%10;
        i++;
    }
    h[x]=key;
}
int searchkey(int h[],int x){
    int key=x%10;
    int i=0;
    while(h[key]!=0 ){
        key=(key+i)%10;
        if(h[key]==x)
        return 1;
        i++;
    }
    return 0;
}
void printkeys(int h[]){
    for(int i=0;i<10;i++){
        if(h[i]!=0)
        cout<<h[i]<<" ";
    }
}
int main(){
    int hash[10]={0};
    int val;
    for(int i=0;i<10;i++){
        cin>>val;
        insertkey(hash,val);
    }
    printkeys(hash);
    int x;
    cin>>x;
    if(searchkey(hash,x))
    cout<<"found key";
    else
    cout<<"Key not found";
    return 0;
}