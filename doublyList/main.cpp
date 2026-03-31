#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int num):data(num),next(nullptr),prev(nullptr){};

};

class doublyList{
    private:
    Node* head;

    public:
        doublyList():head(nullptr){};
        void push(int num){

            Node* temp = new Node(num);
            temp->prev = nullptr;
            temp->next = head;
            if(head!= nullptr){
                head->prev = temp;
            };
            head = temp;
        };
        void display(){
            Node* temp = head;
            std::cout<<"Displaying in forward manner";
            while(temp!= nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            };
        }
        ~doublyList(){
            Node* nextNode= nullptr;
            while(head!= nullptr){
                nextNode = head-> next;
                delete head; 
                head = nextNode;
            };
        };
    
};

int main(){
    doublyList list;
    list.push(1);
    list.push(5);
    list.push(6);
    list.push(9);
    list.push(3);
    list.display();

    return 0;
}