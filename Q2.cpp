// 2. Write a program to implement doubly linked list as an ADT that supports the following operations:


#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
        
    }
    ~Node(){
        if(this->next=NULL){
            delete next;
            next=NULL;
        }
    }
};
Node* head;
Node* tail;

class DLinkedlist{
public:
    DLinkedlist(){}

// i. Insert an element x at the beginning of the doubly linked list

    void insertathead(int d){
   
    Node* temp=new Node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }

}

// ii. Insert an element x at the end of the doubly linked list

    void insertattail(int d){
    
    Node* temp=new Node(d);
    if(tail==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertat(int p,int d){
    if(p==1){
        insertathead(d);
        return;
    }
    Node* temp=head;
    int c=1;
    while(c<p-1){
        temp=temp->next;
        c++;
    }
    if(temp->next==NULL){
        insertattail(d);
        return;

    }

    // Inserting at desired position p:

    Node* newnode=new Node(d);
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next->prev=newnode;
}
// iii. Remove an element from the beginning of the doubly linked list

    void delfront(){
        Node* temp=head;
        temp->next->prev=NULL;
        head=head->next;
        temp->next=NULL;

        delete temp;
    }
// iv. Remove an element from the end of the doubly linked list

    void delend(){
        Node* temp=tail;
        temp->prev->next=NULL;
        tail=tail->prev;
        temp->prev=NULL;

        delete temp;

    }


// Delnode. . . . 
    void delnode(int p){

        if(p==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=head->next;
        temp->next=NULL;

        delete temp;

    }
    
    else{
        Node* curr=head;
        Node* pre=NULL;

        int c=1;
        while(c<p){
            pre=curr;
            curr=curr->next;
            c++;
        }
        
        pre->next=curr->next;
        
        // last element is creating a issue when deleting!!
        if(curr->next==NULL){
            curr->prev=NULL;
            delete curr;
          }
        else{
          curr->next->prev=pre;
          delete curr;}

    }
    

}

void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
};


int main (){

    head=NULL;
    tail=NULL;

    DLinkedlist list;
    list.insertathead(10);
    list.insertattail(20);
    list.insertattail(30);
    list.insertattail(40);

    list.insertat(5, 50);
    list.print();
    list.delfront();
    list.print();
    list.delend();
    list.print();
   

return 0;

}