#include <iostream>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num), next(nullptr){};
};

class queue{
    private:
    Node* front=nullptr;
    Node* rear = nullptr;

    public:
    void enqueue(int num){
        Node* newNode = new Node(num);
        if(front == nullptr){
            newNode->next = front;
            front = newNode;
            rear = newNode;
            return;
        }else{
            rear->next = newNode;
            rear=newNode;
        }
    };
    void denqueue(){
        if(front == nullptr){
            std::cout<<"\nQueue already empty\n";
            return;
        }else{
            Node* temp = front;
            Node* tempNext = front->next;
            delete temp;
            front=tempNext;
        }
    };
}