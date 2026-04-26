#include <iostream>

struct Node{
    char data;
    Node* next;

    Node(char par):data(par){};
};

class Stack{
    private:
    Node* top=nullptr;

    public:
    void push(char parentheses){
        Node* newNode = new Node(parentheses);
        newNode->next = top;
        top = newNode;
    };

    void pop(){
        if(top != nullptr){
            Node* temp = top;
            top = top->next;
            delete temp;
        }else{
            std::cout<<"\nAlready Empty\n";
        };
    };
    char peek(){
        if(top!= nullptr){
            return top->data;
        }else{
            return 0;
        }
    };
    bool isEmpty(){
        if(top == nullptr){
            return true;
        }else{
            return false;
        }
    }
    ~Stack(){
        Node* temp = top;
        Node* tempNext = nullptr;

        while(temp!= nullptr){
            tempNext = temp->next;
            delete temp;
            temp = tempNext;
        };
    };
};

bool isBalanced(std::string equation){
    Stack stack;
    for(char e : equation){
        if(e =='('|| e =='[' || e == '{'){
            stack.push(e);
        }
        if(e ==')'|| e ==']' || e == '}'){
            if(stack.isEmpty()){
                return false;
            }else{
                char tempChar = stack.peek();
                if((e == ')' && tempChar == '(') || (e == ']' && tempChar == '[') || (e == '}' && tempChar == '{')){
                    stack.pop();
                }else{
                    return false;
                }
            }
        }
    }
    return stack.isEmpty();
};


int main() {
    std::string myExpr = "{[()]}";

    std::cout << "Testing expression: " << myExpr << std::endl;

    if (isBalanced(myExpr)) {
        std::cout << "Result: The brackets are Balanced!" << std::endl;
    } else {
        std::cout << "Result: The brackets are Unbalanced!" << std::endl;
    }

    return 0;
};