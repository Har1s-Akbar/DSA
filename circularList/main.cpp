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


    void insertAtIndex(int index , int num){
        if(head == nullptr && index!=0){
            std::cout<<"\nCan not insert at give index because list is empty\n";
            return;
        };
        if(index == 0){
            insertAtHead(num);
            return;
        };
        Node* temp = head;
        int i = 0;
        while(i<index){
            i++;
            temp = temp->next;
            if(temp==head){
                std::cout<<"Out of bound";
                return;
            };
        };
        Node* newNode = new Node(num);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    };

    void display(){
        if (head== nullptr) return;
        Node* temp = head;
        do{
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!= head);
        std::cout<<"\n";
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
    list.insertAtIndex(1,0);
    list.display();
    list.insertAtIndex(3,10);
    list.display();
    return 0;
}