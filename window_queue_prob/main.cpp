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
    };
    void dequeue(){
            if(front == nullptr){
                rear = nullptr;
                std::cout<<"\n empty\n";
                return;
            }
            Node* temp = front;
            front = front->next;
            if(front != nullptr){
            front->prev = nullptr;
            }else{
                rear = nullptr;
            }
            delete temp;
        }
    void popRear(){
            if(rear == nullptr){
                front = nullptr;
                std::cout<<"\nQueue empty\n";
                return;
            };
            Node* temp = rear;
            rear= rear->prev;
            if(rear!= nullptr){
                rear->next =nullptr;
            }else{
                front = nullptr;
            };
            delete temp;
        }
        int peekFront(){
            if(front == nullptr){
                std::cout<<"\nQueue is empty\n";
                return 0;
            };
            return front->data;
        };
        int peekRear(){
            if(rear == nullptr){
                std::cout<<"\nQueue is empty\n";
                return 0;
            };
            return rear->data;
        };

        bool isEmpty(){
            if(front == nullptr){
                return 1;
            };
            return 0;
        };

        ~Dequeue(){
            Node* temp = front;
            Node* tempNext = nullptr;
            while(temp != nullptr){
                tempNext = temp->next;
                delete temp;
                temp=tempNext;
            };
        }
};

int maximumSlidingWindow(int array[],int n, int window ){
    Dequeue queue;
    int num=0;
    for(int i =0; i<n;i++){
        while(!queue.isEmpty() && queue.peekRear()<array[i]){
            queue.popRear();
        };
        queue.enqueue(array[i]);

        if(i>window){
            if(array[i-window] == queue.peekFront()){
                queue.dequeue();
            }
        };
        if(i>=window-1){
            std::cout<<"\nThe biggest number in our sliding window is \n"<<queue.peekFront()<<"\n";
        };
    };
};

int main(){
    int array1[10]={1,5,32,9,8,0,1,7,2,3};
    
}