#include <iostream>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num){};
};

class Stack_postfix{
    private:
    Node* top=nullptr;

    public:
    void push(int num){
        Node* newNode = new Node(num);
        newNode->next = top;
        top = newNode;
    };
    void pop(){
        if(top != nullptr){
        Node* temp = top;
        top= top->next;
        delete temp;
        }else{
            std::cout<<"\nCan not pop, stack already empty\n";
        }
    };
    int peek(){
        if(top != nullptr){
            return top->data;
        }else{
            std::cout<<"\nStack is empty";
            return -1;
        };
    };
};

int evaluatedPostfix(std::string expression){
    Stack_postfix stack;
    for(char single: expression){
        if(std::isdigit(static_cast<unsigned char>(single))){
            stack.push(single);
        }else if(single == '/'||single =='+'||single=='-'||single=='*'){
         int val1 = stack.peek();
         stack.pop();
         int val2 = stack.peek();
         stack.pop();
         if(single =='+') return (val2+val1);
         if(single =='-') return (val2-val1);
         if(single =='*') return (val2*val1);
         if(single =='/') return (val2/val1);
        }else{
            std::cout<<"\nNot a correct expression\n";
        };
    };
    return 0;
};

int main(){
    int result = evaluatedPostfix("66-");
    std::cout<<result;
}
