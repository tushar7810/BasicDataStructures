#include<iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
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
    }
    else{
        newnode -> value = val;
        newnode -> next = NULL;
        return newnode;
    }
}
void create_list(int n){
    snode *newnode,*temp;
    for(int i = 0;i<n;i++){
        newnode = create_node();
        if(first == NULL){
            first = newnode;
            first -> next = NULL;
        }else{
            temp = first;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newnode;
        }
    }
}
void insert_first(){
    snode *newnode,*temp;
    newnode = create_node();
    if(first == NULL){
        first = newnode;
        first -> next = NULL;
    }else{
        temp = first;
        first = newnode;
        first ->next = temp;
    }
}
void insert_end(){
    snode *newnode,*temp,*prev;
    newnode = create_node();
    if(first == NULL){
        first = newnode;
        first -> next = NULL;
    }else{
        temp = first;
        prev = first;
        while(temp -> next != NULL){
            prev = temp;
            temp = temp ->next;
        }
        temp -> next = newnode;
        newnode->next=NULL;
    }
}
void insert_pos(){
    snode *newnode,*temp;
    int i=1,pos;
    cout<<"Enter the position : ";
    cin>>pos;
    newnode = create_node();
    if(i>pos){
        cout<<"Invalid Position"<<endl;
    }else{
        temp = first;
        while(i<pos){
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    } 
}
void delete_first(){
    snode *temp;
    if(first == NULL){
        cout<<"List is empty"<<endl;
    }else{
        temp = first;
        first = temp -> next;
        free(temp);
    }
}
void delete_pos(){
    int i = 1,pos;
    snode *temp,*prev;
    cout<<"Enter the position : ";
    cin>>pos;
    if(first == NULL){
        cout<<"List is Empty"<<endl;
    }else{
        if(i>pos){
            cout<<"Invalid Position"<<endl;
        }
        else{
            temp = first;
            prev = first;
            while(i<pos){
                prev = temp;
                temp = temp -> next;
                i++;
            }
            prev -> next = temp -> next;
        }
        free(temp);
    }
}
void delete_end(){
    snode *temp,*prev;
    if(first == NULL){
        cout<<"List is Empty"<<endl;
    }else{
        temp = first;
        prev = first;
        while(temp -> next != NULL){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        free(temp);
    }
}
void display(){
    snode *temp;
    temp = first;
    if(first == NULL){
        cout<<"List is Empty"<<endl;
    }else{
        cout<<"The values are : ";
        while(temp != NULL){
            cout<<temp -> value<<" ";
            temp = temp ->next;
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
            case 1: cout<<"Enter the length of the list : ";
                    cin>>length;
                    create_list(length);
                    break;
            case 2: insert_first();
                    break;
            case 3: insert_end();
                    break;
            case 4: insert_pos();
                    break;
            case 5: delete_first();
                    break;
            case 6: delete_pos();
                    break;
            case 7: delete_end();
                    break;
            case 8: display();
                    break;
            case 9: exit(0);
                    break;
            default : exit(0);
        }
    }while(1);
    return 0;
}