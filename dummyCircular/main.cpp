#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int num):data(num){};
};

class DummyCircular{
    private:
    Node* head;

    public:
    DummyCircular(){
        Node* dummy = new Node(-1);
        head = dummy;
        dummy->next = head;
        dummy->prev = dummy;
    };

    void insertAtHead(int num){
        Node* newNode = new Node(num);
        newNode->prev = head;
        newNode->next = head->next;
        
        head->next->prev= newNode;
        head->next = newNode;
    };

    void insertAtN(int index, int num){
        Node* temp = head;
        int i =0;
        while(i<=index){
            i++;
            temp = temp->next;
            if(temp == head){
                std::cout<<"\nOut of bound, index does not exist\n";
                return;
            };
        };
        Node* newNode = new Node(num);
        newNode->prev = temp->prev;
        newNode->next = temp;

        temp->prev->next = newNode;
        temp->prev = newNode;
    };
    void display(){
        Node* temp = head->next;
        while(temp != head){
            std::cout<<temp->data<<" ";
            temp = temp->next;
        };
        std::cout<<"\n";
    };
    ~DummyCircular(){
        Node* temp = head->next;
        Node* tempNext = nullptr;
        
        while(temp != head){
            tempNext = temp->next;
            delete temp;
            temp=tempNext;
        }
        delete head;
    };
};

int main(){

    DummyCircular list;
    list.insertAtHead(2);
    list.insertAtHead(4);
    list.insertAtHead(8);
    list.insertAtHead(9);
    list.display();
    list.insertAtN(2,0);
    list.display();
    list.insertAtN(8,3);
    return 0;
}