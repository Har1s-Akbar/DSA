#include <iostream>

struct Point{
    int data;
    Point* next;

    Point(int num):data(num){};
};

class Stack{
    private:
        Point* head=nullptr;

    public:
    void push(int num){
        Point* newPoint = new Point(num);
        newPoint->next = head;
        head = newPoint;
    };
    void pop(){
        Point* temp = head;
        if(head == nullptr){
            std::cout<<"Stack is already empty\n";
            return;
        };
        head = head->next;
        delete temp;
    };
    int peak(){
        Point* temp = head;

        if(temp != nullptr){
            return temp->data;
        }else{
            return -1;
        };
    };

};

int main(){
    Stack stack;
    stack.peak();
    stack.push(3);
    stack.push(6);
    stack.push(9);
    stack.push(0);
    stack.push(18);
    int num =stack.peak();
    std::cout<<num<<"\n";
    stack.pop();
    stack.pop();
    stack.pop();
    int num1 = stack.peak();
    std::cout<<num1<<"\n";
    return 0;
}