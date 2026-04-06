#include <iostream>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num), next(nullptr){};
};

class Queue{
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
    void dequeue(){
        if(front == nullptr){
            std::cout<<"\nQueue already empty\n";
            return;
        }else{
            Node* temp = front;
            Node* tempNext = front->next;
            delete temp;
            front=tempNext;

            if(front == nullptr){
                rear = nullptr;
            }
        };
    };

    int peek(){
        if(front == nullptr){
            std::cout<<"\nQueue is empty\n";
            return -1;
        };
        return front->data;
    }
    ~Queue(){
        while(front!= nullptr){
            dequeue();
        };
    }
};

int main(){
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    std::cout<<"\nNow Dequeue and peek in alternate\n";
    int a = queue.peek();
    std::cout<<"\n"<<a<<"\n";
    queue.dequeue();
    int b = queue.peek();
    std::cout<<"\n"<<b<<"\n";
    queue.dequeue();
    int c = queue.peek();
    std::cout<<"\n"<<c<<"\n";
    queue.dequeue();
    int d = queue.peek();
    std::cout<<"\n"<<d<<"\n";
    queue.dequeue();

    queue.dequeue();

    return 0;
};