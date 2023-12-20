#include<bits/stdc++.h>
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
        cout<<"Memory is not allocated"<<endl;
    }else{
        newnode -> value = val;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }
}
void create_list(int n){
    snode *newnode,*temp;
    for(int i=0;i<n;i++){
        newnode = create_node();
        if(first == NULL){
            first = newnode;
            first -> prev = NULL;
            first -> next = NULL;
        }
        else{
            temp = first;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newnode;
            newnode ->prev = temp;
        }
    }
    
}
void insert_first(){
    snode *temp,*newnode;
    newnode = create_node();
    if(first == NULL){
        cout<<"List is empty"<<endl;
    }else{
        temp = first;
        first = newnode;
        temp ->prev = first;
        first ->prev = NULL;
        first ->next = temp;
    }
}
void insert_pos(){
    snode *temp,*newnode,*pri;
    int i=1,c=0,pos;
    temp = first;
    while(temp != NULL){
        temp = temp -> next;
        c++;
    }
    if(first == NULL){
        cout<<"List is Empty"<<endl;
    }else{
        cout<<"Enter the Position : ";
        cin>>pos;
        if(i>pos){
            cout<<"Invalid Position"<<endl;
        }else{
            if(pos>0 || pos<c){
                pri = first;
            temp = first;
            for(;i<pos;i++){
                pri = temp;
                temp = temp -> next;
            }
            pri -> next = newnode;
            newnode -> next =temp;
            newnode -> prev = pri;
            }
        }
    }
}
void insert_end(){
    snode *temp,*newnode;
    newnode = create_node();
    if(first == NULL){
        cout<<"List is empty"<<endl;
    }else{
        temp = first;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newnode;
        newnode -> prev = temp;
    }
}
void delete_first(){
    snode *temp;
    if(first == NULL){
        cout<<"List is Empty"<<endl;
    }
    else{
        temp = first;
        first = temp ->next;
        free(temp);
    }
}
void delete_pos(){

}
void delete_end(){
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
void display_forword(){
    snode *temp;
    temp = first;
    if(first == NULL){
        cout<<"List is empty"<<endl;
    }else{
        cout<<"Elements are : ";
        while(temp != NULL){
            cout<<temp ->value<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
}
void display_backword(){
    snode *temp;
    temp = first;
    if(first == NULL){
        cout<<"List is Empty. Nothing to display"<<endl;
    }
    else{
        // temp = first;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        cout<<temp->value;
        cout<<"The values are : ";
        while(temp != NULL){
            cout<<temp -> value<<" ";
            temp = temp -> prev;
            
        }
        cout<<endl;
    }
}
int main(){
    int ch,length;
    do{
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the length of the linked List : ";
                    cin>>length;
                    create_list(length);
                    break;
            case 2: display_forword();
                    break;
            case 3: insert_first();
                    break;
            case 4: insert_pos();
                    break;
            case 5: insert_end();
                    break;
            case 6: delete_first();
                    break;
            case 7: delete_pos();
                    break;
            case 8: delete_end();
                    break;
            case 9: display_backword();
                    break;
            default: exit(0);
        }
    }while(1);
    return 0;
}