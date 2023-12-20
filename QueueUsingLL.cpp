#include<iostream>
using namespace std;
struct node{
    int value;
    struct node *prev;
    struct node *next;
};
typedef struct node dnode;
dnode *first = NULL;
dnode *create_node(){
    int val;
    cout<<"Enter the value : ";
    cin>>val;
    dnode *newnode = (dnode *)malloc(sizeof(dnode));
    if(newnode == NULL){
        cout<<"Memory was not allocated"<<endl;
    }else{
        newnode -> value = val;
        newnode -> prev = NULL;
        newnode -> next = NULL;
    }
    return newnode;
}
void enqueue(){
    dnode *newnode,*temp;
    newnode = create_node();
    if(first == NULL){
        first = newnode;
    }else{
        temp = first;
        while(temp ->next != NULL){
            temp = temp ->next;
        }
        temp -> next = newnode;
        newnode ->prev = temp;
    }
}
void dequeue(){
    dnode *temp;
    if(first == NULL){
        cout<<"Queue Underflow"<<endl;
    }else{
        temp = first;
        first = temp -> next;
        free(temp);
    }
}
void display(){
    dnode *temp;
    temp = first;
    while(temp != NULL){
        cout<<temp -> value <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    int ch;
    do{ 
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            default : exit(0);
        }
    }while(1);
    return 0;
}

