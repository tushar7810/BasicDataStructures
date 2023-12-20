#include<iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node snode;
snode *first = NULL;
snode *create_node(){
    int val;
    cout<<"Enter the value : ";
    cin>>val;
    snode *newnode = (snode *)malloc(sizeof(snode));
    if(newnode == NULL){
        cout<<"Memory was not allocated"<<endl;
    }else{
        newnode -> value = val;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }
    return newnode;
}
void push(){
    snode *temp,*newnode;
    newnode = create_node();
    if(first == NULL){
        first = newnode;
    }else{
        temp = first;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
    }
}
void pop(){
    snode *temp,*pre;
    temp = first;
    pre = first;
    while(temp -> next != NULL){
        pre = temp;
        temp = temp -> next;
    }
    pre -> next = NULL;
    temp -> prev = NULL;
    free(temp);
}
void display(){
    snode *temp = first;
    while(temp -> next != NULL){
        temp = temp ->next;
    }
    while(temp != NULL){
        cout<<temp ->value<<" ";
        temp = temp ->prev;
    }
    cout<<endl;
}
int main(){
    int ch;
    do{ 
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            default : exit(0);
        }
    }while(1);
    return 0;
}