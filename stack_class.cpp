#include<iostream>
using namespace std;
#define max 5
int stack[max];
class clsstk{
    private: 
        int top;
    public: 
        clsstk(){
            top = -1;
        };
        void push();
        void push(){
            int val;
            cout<<"Enter the value : ";
            cin>>val;
            if(top >= max -1){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                stack[++top] = val;
            }
        }
        void pop(){
            if(top < 0){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                cout<<"DEleted element is : "<<stack[top]<<endl;
                top--;
            }
        }
        void display(){
            if(top < 0){
                cout<<"Stack is empty"<<endl;
            }else{
                cout<<"Elements are : ";
                for(int i=top;i>=0;i--){
                    cout<<stack[i]<<" ";
                }
                cout<<endl;
            }
        }
};  
void clsstk:: push(){
        int val;
        cout<<"Enter the value : ";
        cin>>val;
        if(top >= max -1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            stack[++top] = val;
        }
}
int main(){
    clsstk c;
    int ch;
    do{
    cout<<"enter your choice : ";
    cin>>ch;
        switch(ch){
        case 1: c.push();
                break;
        case 2: c.pop();
                break;
        case 3: c.display();
                break;
        case 4: exit(0);
                break;
    }
    }while(1);
    return 0;
}

