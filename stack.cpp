#include<iostream>
using namespace std;
#define max 5
int top = -1;
int a[max];
void push(){
    int val;
    cout<<"Enter the value : ";
    cin>>val;
    if(top >= max-1){
        cout<<"Stack Overflow"<<endl;
    }else{
        a[++top] = val;
    }
}
int pop(){
    if(top < 0){
        cout<<"Stack Underflow"<<endl;
    }else{
        int x = a[top--];
        return x;
    }
}
void display(){
    int i;
    if(top >= 0){
        cout<<"Stack element's are : ";
        for(i=top;i>=0;i--){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int ch;
    do{
        cout<<"Stack Operation"<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
        }
    }while(1);
    return 0;
}