#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int num):data(num),next(nullptr), prev(nullptr){};
};

class Dequeue{
    private:
    Node* front=nullptr;
    Node*rear = nullptr;

    public:
    void enqueue(int num){
        Node* newNode = new Node(num);
        if(front == nullptr){    
            newNode->next = front;
            front = newNode;
            rear = newNode;
            return;
        }else{
            rear->next =newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        void dequeue(){
            if(front == nullptr){
                rear == nullptr;
                std::cout<<"\n empty\n";
                return;
            }else{
                Node* temp = front;
                front = front->next;
                front->prev = nullptr;
                delete temp;
            };
        }
        void popRear(){
            if(rear == nullptr){
                front == nullptr;
                std::cout<<"\nQueue empty\n";
            };
            Node* temp = rear;
            rear= rear->prev;
            rear->prev->next =nullptr;
        };
    }
};