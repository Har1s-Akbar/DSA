#include <iostream>

struct Point{
    int data;
    Point* next;

    Point(int num):data(num){};
};

class Stack{
    private:
        Point* top=nullptr;

    public:
    void push(int num){
        Point* newPoint = new Point(num);
        newPoint->next = top;
        top = newPoint;
    };
    void pop(){
        Point* temp = top;
        if(top == nullptr){
            std::cout<<"Stack is already empty\n";
            return;
        };
        top = top->next;
        delete temp;
    };
    int peek(){
        Point* temp = top;

        if(temp != nullptr){
            return temp->data;
        }else{
            return -1;
        };
    };

    bool isEmpty(){
        if(top==nullptr){
            return true;
        }else{
            return false;
        };
    };

    ~Stack(){
        Point* temp = top;
        Point* tempNext = nullptr;
        while(temp!= nullptr){
            tempNext= temp->next;
            delete temp;
            temp = tempNext;
        }
    };

};

int main(){
    Stack stack;
    bool empty = stack.isEmpty();
    std::cout<<"Is stack empty "<<empty<<"\n";
    stack.peek();
    stack.push(3);
    stack.push(6);
    stack.push(9);
    stack.push(0);
    stack.push(18);
    bool empty1 = stack.isEmpty();
    std::cout<<"Is stack empty "<<empty1<<"\n";
    int num =stack.peek();
    std::cout<<num<<"\n";
    stack.pop();
    stack.pop();
    stack.pop();
    int num1 = stack.peek();
    std::cout<<num1<<"\n";
    return 0;
}