#include <iostream>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num), next(nullptr){};
};
class Stack{
    private:
    Node* top = nullptr;

    public:
    void push(int num){
        Node* newTop = new Node(num);
        newTop->next = top;
        top=newTop;
    }
    void pop(){
        Node* tempTop =  top;
        if(tempTop!= nullptr){
            top = top->next;
            delete tempTop;
        }else{
            std::cout<<"\nCan not delete list is already empty\n";
            return;
        }
    };

    int peek(){
        Node* tempTop = top;
        if(tempTop == nullptr){
            return tempTop->data;
        }else{
            std::cout<<"\nList is empty\n";
            return 0;
        };
    }

    ~Stack(){
        Node* tempTop = top;
        Node* nextTop = nullptr;

        while(tempTop!= nullptr){
            nextTop = tempTop->next;
            delete tempTop;
            tempTop = nextTop;
        }
    }

};


class LinkedList{
    private:
        Node* head = nullptr;
    public:
    void insert(int num){
        Node* newNode = new Node(num);
        newNode->next = head;
        head = newNode;
    };
    void display(){
        Node* temp = head;
        while(temp!= nullptr){
            std::cout<<temp->data<<" ";
            temp= temp->next;
        }
        std::cout<<"\n";
    };
    
    ~LinkedList(){
        Node* temp = head;
        Node* tempNext = nullptr;
        while(temp!= nullptr){
            tempNext = temp->next;
            delete temp;
            temp = tempNext;
        }
    }
};

int main(){

};