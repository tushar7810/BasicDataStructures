#include<iostream>
using namespace std;
#define max 5
int queue1[max];
class queue{
    private:
        int front,rear;
    public: 
        queue(){//constructor
            front = -1;
            rear = -1;
        }
        void enqueue(){
            int val;
            cout<<"Enter the value : ";
            cin>>val;
            if(rear >= max-1){
                cout<<"Queue Overflow"<<endl;
            }
            else{
                if(front == -1){
                    front = 0;
                    rear++;
                    queue1[rear] = val;
                }
                else{
                    rear++;
                    queue1[rear] = val;
                }
            }
        }
        void dequeue(){
            if(front == -1 || front >rear){
                cout<<"Underflow"<<endl;
            }
            else{
                cout<<"Deleted element is : "<<queue1[front];
                front++;
            }
        }
        void display(){
            if(front == -1 || front > rear){
                cout<<"Queue is Empty"<<endl;
            }else{
                int i;
                for(i=0;i<=rear;i++){
                    cout<<queue1[i]<<" ";
                }
                cout<<endl;
            }
        }
};
int main(){
    class queue q;  
    int ch;
    do{
        cout<<"Queue Operation"<<endl;
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1: q.enqueue();
                    break;
            case 2: q.dequeue();
                    break;
            case 3: q.display();
                    break;
            case 4: exit(0);
                    break;
        }
    }while(1);
    return 0;
}