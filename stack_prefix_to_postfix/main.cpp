#include  <iostream>
#include <string>

struct Node{
    std::string data;
    Node* next;

    Node(std::string num):data(num), next(nullptr){};
};

class Stack{
    private:
    Node* top=nullptr;

    public:
    void push(std::string data){
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    };
    std::string peek(){
        if(top == nullptr){
            return "0";
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
    for(int i = expression.length()-1; i>=0;i--){
        char single =expression[i];
        if(std::isdigit(single)){
            stack.push(std::string(1,single));
        }else if(single == '+' || single == '-' || single == '*' || single == '/'){
            std::string s1 = stack.peek(); stack.pop();
            std::string s2 = stack.peek();stack.pop();

            std::string final = s1 + s2 + single;
            stack.push(final);
        }
    };
    return stack.peek();
};

int main(){
    std::string fin = conversion("/98");
    std::cout<<fin;
}