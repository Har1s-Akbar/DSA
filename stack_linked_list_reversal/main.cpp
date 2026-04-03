#include <iostream>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num), next(nullptr){};
};

struct StackNode{
    Node* node;
    StackNode* next;

    StackNode(Node* &ptr):node(ptr), next(nullptr){};
};
class Stack{
    private:
    StackNode* top = nullptr;

    public:
    void push(Node* ptr){
        StackNode* newNode = new StackNode(ptr);
        newNode->next = top;
        top = newNode;
    };
    void pop(){
        StackNode* temp = top;
        if(top == nullptr){
            std::cout<<"\nCan not pop, stack already empty\n";
            return;
        };
        top = top->next;
        delete temp;
    };
    StackNode* peek(){
        if(top == nullptr){
            std::cout<<"Can not peek, stack empty;";
            return 0;
        }else{
            return top->next;
        };
    };
    ~Stack(){
        StackNode* temp = top;
        StackNode* tempNext = nullptr;
        while(temp!= nullptr){
            tempNext = temp->next;
            delete temp;
            temp=tempNext;
        }
    };
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

    void reverse(){
        Stack stack;
        Node* temp = head;



    }
    
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