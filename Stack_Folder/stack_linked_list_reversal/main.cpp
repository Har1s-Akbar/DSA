#include <iostream>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num), next(nullptr){};
};

struct StackNode{
    Node* data;
    StackNode* next;

    StackNode(Node* &ptr):data(ptr), next(nullptr){};
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
    Node* peek(){
        if(top == nullptr){
            std::cout<<"Can not peek, stack empty;";
            return 0;
        }else{
            return top->data;
        };
    };
    ~Stack(){
        StackNode* temp = top;
        StackNode* tempNext = nullptr;
        while(temp!= nullptr){
            tempNext = temp->next;
            delete temp;
            temp=tempNext;
        };
    };
    bool isEmpty(){
        if(top == nullptr){
            return 1;
        }else{
            return 0;
        };
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

    void reverse(){
        Stack stack;
        Node* temp = head;
        while(temp != nullptr){
            stack.push(temp);
            temp=temp->next;
        };

        head = stack.peek();
        Node* tempN = head;
        stack.pop();
        while(stack.peek() != nullptr){
             tempN->next = stack.peek();
             stack.pop();
             tempN = tempN->next;
        };
        tempN->next = nullptr;
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

int main() {
    LinkedList myList;
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);
    myList.insert(40);
    std::cout << "Original List: ";
    myList.display();
    std::cout << "Reversing the list using the Stack..." << std::endl;
    myList.reverse();
    std::cout << "Reversed List: ";
    myList.display();
    return 0;
}