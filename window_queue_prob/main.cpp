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
                std::cout<<"\n empty\n";
                return;
            }else{
                
            }
        }
    }
};