#include  <iostream>
#include <string>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num), next(nullptr){};
};

class Stack{
    private:
    Node* top=nullptr;

    public:
    void push(int data){
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    };
    int peek(){
        if(top == nullptr){
            return 0;
        }else{
            return top->data;
        };
    };
    void pop(){
        if(top == nullptr){
            std::cout<<"\nAlready empty\n";
            return;
        }else{
            Node* temp = top;
            top = top->next;
            delete temp;
        };
    };
    ~Stack(){
        Node* temp = top;
        Node* tempNext = nullptr;
        while(temp!= nullptr){
            tempNext = temp->next;
            delete temp;
            temp =  tempNext;
        };
    };
};

std::string conversion(std::string expression){
    Stack stack;
    for(int i = expression.length()-1; i <=0;i--){
        if(std::isdigit(static_cast<unsigned char>(expression[i]))){
            stack.push(expression[i]);
        }else if(expression == "/" ||expression == "*" ||expression == "-" ||expression == "+"){
            int val1 = stack.peek();
            stack.pop();
            int val2 = stack.peek();
            stack.pop();
            expression[3] = expression[i];
            expression[2] = val1;
            expression[1] = val2;
        }
    };
    return expression;
};

int main(){
    std::string result = conversion('+42');
    std::cout<<result;
}