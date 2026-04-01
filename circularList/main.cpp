#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int num):data(num),next(nullptr),prev(nullptr){};
};

class DoublyCircularList{
    private:
        Node* head;

    public:
        DoublyCircularList():head(nullptr){};
        
    void insertAtHead(int num){
        Node* newNode = new Node(num);
        if(head == nullptr){
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        };
        Node* temphead = head;
        newNode->prev = temphead->prev;
        temphead->prev->next = newNode;
        temphead->prev = newNode;
        newNode->next = head;
        head = newNode;
    };
    void display(){
        if (head== nullptr) return;
        Node* temp = head;
        do{
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!= head);
    };
    ~DoublyCircularList(){
        if(head == nullptr) return;
        Node* temp = head;
        Node* nextNode =  nullptr;
        temp->prev->next = nullptr;
        while(temp!= nullptr){
            nextNode = temp->next;
            delete temp;
            temp= nextNode;
        };
    }
};
int main(){
    DoublyCircularList list;
    list.insertAtHead(2);
    list.insertAtHead(5);
    list.insertAtHead(7);
    list.display();
    return 0;
}