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
    void displayReverseFun(Node* head){
        if(head== nullptr){
                return;    
            };
        displayReverseFun(head->next);
        std::cout<<head->data<<" ";
        };

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
        void displayForward(){
            Node* temp = head;
            std::cout<<"Displaying in forward manner\n";
            while(temp!= nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            };
        };
        void displayReverse(){
            displayReverseFun(head);
        };

        void insertAtIndex(int index, int num){
            if(index == 0){
                push(num);
            };

            int i = 0;
            Node* temp = head;
            Node* newNode = new Node(num);
            while(temp!=nullptr && i<index){
                i++;
                temp= temp->next;
            };
                newNode->prev = temp->prev;
                newNode->next = temp;
                if(temp->prev != nullptr){
                temp->prev->next=newNode;
                };
                temp->prev = newNode;
        };
        void deleteAtIndex(int index){
            int i =0;
            Node* temp = head;
            if(head == nullptr){
                std::cout<<"\nThe list is already empty\n";
                return;
            };
            if(index == 0){
                head = temp->next;
                if(head!= nullptr){
                    temp->next->prev = nullptr;
                };
                delete temp;
                return;
            };
            while(temp != nullptr && i<index){
                i++;
                temp=temp->next;
            };
            if(temp == nullptr){
                std::cout<<"\nthe index does not exist\n";
                return;
            };
            if(temp->next != nullptr){
            temp->next->prev = temp->prev;
            };
            temp->prev->next = temp->next;
            delete temp;
        };
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
    list.displayForward();
    std::cout<<"\nReverse print"<<"\n";
    list.displayReverse();
    list.insertAtIndex(2,50);
    list.displayForward();
    list.deleteAtIndex(7);
    list.deleteAtIndex(2);
    list.push(4);
    list.displayForward();
    return 0;
}