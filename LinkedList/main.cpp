#include <iostream>

struct Node{
	int data;
	Node* next;

	Node(int num):data(num),next(nullptr){}
};

class LinkedList{
	private:
		Node* head = nullptr;

	public:
		void insert(int i, int numInsert){
			Node* tempCurrent = head;
			Node* previous = nullptr;
			int index = 0;
			if(i == 0){
				Node* temp = new Node(numInsert);
				temp->next = head;
				head = temp;
			}else{
				while(tempCurrent != nullptr && index < i){
					previous = tempCurrent;
					tempCurrent= tempCurrent->next;
				index++;
				};
				Node * temp = new Node(numInsert);
				temp->next = tempCurrent;
				previous->next = temp;
			}
		}
		void printList(){
			Node* temp = head;

			while(temp!= nullptr){
				std::cout<<temp->data<<" ";
				temp = temp->next;
			}
		};
		~LinkedList(){
			Node* current = head;
			while(current != nullptr){
				Node* next  = current->next;
				delete current;
				current = next;
			};
		}
		
};

int main(){
	LinkedList list;
	list.insert(0,2);
	list.insert(0,3);
	list.insert(0,5);
	std::cout<<"first Print list initializing\n";
	list.printList();
	list.insert(1,7);
	std::cout<<"second Print actual insertion at index 1\n";
	list.printList();
	list.insert(2,10);
	std::cout<<"second Print actual insertion at index 2\n";
	list.printList();
}