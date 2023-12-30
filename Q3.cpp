// 3. Write a program to implement circular linked list as an ADT which supports the following 
// operations:



#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free now for value " << value << endl;
    }

};

Node* tail;

class CLinkedlist{
public:
    CLinkedlist(){}

// i. Insert an element x in the list

    void insertNode(int element, int d) {
    
        if(tail == NULL) {
            Node* newNode = new Node(d);
            tail = newNode;
            newNode -> next = newNode;
        }
        else{

            Node* curr = tail;

            while(curr->data != element) {
                curr = curr -> next;
            }

            Node* temp = new Node(d);
            temp -> next = curr -> next;
            curr -> next = temp;
            }
        }    

    void print() {

        Node* temp = tail;

        if(tail == NULL) {
            cout << "List is Empty "<< endl;
            return ;
        }

        do {
            cout << tail -> data << " ";
            tail = tail -> next;
        } while(tail != temp);

        cout << endl;
} 


// ii. Remove an element from the list

    void deleteNode(int value) {
    
        if(tail == NULL) {
            cout << " List is empty, please check again" << endl;
            return;
        }
        else{

            Node* prev = tail;
            Node* curr = prev -> next;

            while(curr -> data != value) {
                prev = curr;
                curr = curr -> next;
            }

            prev -> next = curr -> next;


            if(curr == prev) {
                tail = NULL;
            }

            else if(tail == curr ) {
                tail = prev;
            }

            curr -> next = NULL;
            delete curr;

    }


}

// iii. Search for an element x in the list and return its pointer

     Node* search(int x){
        Node* res= nullptr;
        Node* temp=tail;
        do{
            if(temp->data==x){
                res= temp;
            }
            temp=temp->next;
        }while(temp!=tail);
        

        if(res!=nullptr){
            cout<<"Element found at address: "<<res<<endl;
            
        }
        else{
            cout<<"Element not found!"<<endl;
        }

        return res;
    }


};
int main() {

    Node* tail = NULL;

    CLinkedlist list;

    list.insertNode(1, 3);
    list.insertNode(3, 5);

    list.insertNode(5, 9);
    list.insertNode(9, 11);

    list.insertNode(5, 7);
    list.print();

    
    list.deleteNode(5);
    list.print();

    list.insertNode(11,100);
    list.print();

    list.search(100);




    


    return 0;
}