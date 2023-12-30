// 5. Implement Queue as an ADT.

#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int front,rear,size;
public:

    Queue(int n){
        size=n;
        arr=new int[n];
        front=-1;
        rear=-1;
    }

    void enqueue(int e){
        if(front==(rear+1)%size){                                      // If Full
            cout<<"Queue is Full!"<<endl;                               

        }
        else if(front==-1){                                            // First element is being pushed 
            front=rear=0;
            arr[rear] = e;
        }
        else if(rear== size-1 && front!=0){                            // Maintaining cyclic nature
            rear=0;
            arr[rear]=e;
        }
        else{                                                          // Normal flow.....
            rear++;                                                    // Pushing......
            arr[rear]=e;
        }
    }


    void dequeue(){
        if(front==-1){                                  // Queue is empty 
            cout<<"Queue is empty!"<<endl;
        }

        if(front==rear){                                // Single element is present 
            front =-1;                                  
            rear = -1;
            cout<<"front==rear"<<endl;
        }
        else if(front==size-1){                         // Maintaining Cycle
            front =0;
        }
        else{
            front++;                                   // Normal Flow.
        }

    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;

        }
        else{
            return false;
        }

    }

    bool isFull(){
        if(front==(rear+1)%size){
            return true;
        }
        else{
            return false;
        }
    }

    void getfront(){
        cout<<arr[front]<<endl;
    }


    void showq(){

        int temp=front;

        if (front == -1) {
            cout << "Queue is empty!"<< endl;
            return;
        }

        do{
            cout<<arr[temp]<<" ";
            temp=(temp+1) %size;

        }while(temp!=(rear+1)%size);

    }
};


int main (){

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.enqueue(60);
    // q.enqueue(70);
    q.showq();


    // cout<<q.isEmpty();
    // cout<<endl;
    // q.enqueue(5);
    
    // cout<<q.isEmpty();
    // cout<<endl;
    // q.getfront();

return 0;
}