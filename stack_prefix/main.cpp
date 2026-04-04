#include  <iostream>

struct Node{
    int data;
    Node* next;

    Node(int num):data(num), next(nullptr){};
};

class StackPrefix{
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
    ~StackPrefix(){
        Node* temp = top;
        Node* tempNext = nullptr;
        while(temp!= nullptr){
            tempNext = temp->next;
            delete temp;
            temp =  tempNext;
        };
    };
};


int evaluatePrefix(std::string expression){
    StackPrefix stack;
    for(int i = expression.length()-1; i>=0;i--){
        if(std::isdigit(static_cast<unsigned char>(expression[i]))){
            stack.push(expression[i]-'0');
        }else if(expression[i] == '+' || expression[i] == '/' || expression[i] == '*' ||expression[i] == '-'){
            int val1 = stack.peek();
            stack.pop();
            int val2 = stack.peek();
            stack.pop();

            if(expression[i]=='+') stack.push(val1+val2);
            if(expression[i]=='*') stack.push(val1*val2);
            if(expression[i]=='/') stack.push(val1/val2);
            if(expression[i]=='-') stack.push(val1-val2);
        }
    }
    return stack.peek();
};

int main(){
    int result = evaluatePrefix("/62");
    std::cout<<result;
    return 0;
};