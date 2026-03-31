#include <iostream>

struct Node{
	int data;
	Node* next;

	Node(int num):data(num),next(nullptr){}
};

class LinkedList{
	private:
		Node* head = nullptr;
		// I moved the recursive method to the private field of our class because recursive method required the use of head which is
		// a private field, So instead of asking the user to pass the head we are using another function reverse(), which will 
		// check if the head == nullptr then it will return the control to the function because we can not reerse a null linked list
		// but if it is not empty then the control is handed over to our recursive function
		Node* reversalRecursive(Node* head){
			if(head->next== nullptr || head == nullptr){
				return head;
			};

			Node* newHead = reversalRecursive(head->next);
			head->next->next = head;

			head->next = nullptr;

			return newHead;
		};

	public:
		void insert(int i, int numInsert){
			Node* temp = new Node(numInsert);
			Node* tempCurrent = head;
			Node* previous = nullptr;
			int index = 0;
			if(i == 0){
				temp->next = head;
				head = temp;
				return;
			}else{
				while(tempCurrent != nullptr && index < i){
					previous = tempCurrent;
					tempCurrent= tempCurrent->next;
				index++;
				};
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

		void deleteNode(int index){
			Node* nodeCurrent = head;
			Node* prevNode = nullptr;

			int i = 0;
			if(head == nullptr){
				std::cout<<"The list is already empty\n";
				return;
			}
			if(index == 0){
				Node* temp = head;
				head = head->next;
				delete temp;
				return;
			}
			while(nodeCurrent != nullptr && i<index){
				prevNode = nodeCurrent;
				nodeCurrent = nodeCurrent->next;
				i++;
			}
			if(nodeCurrent == nullptr){
				std::cout<<"Array out of Bounds\n";
				return;
			}
			prevNode->next = nodeCurrent->next;
			delete nodeCurrent;
			
		};
// Iterative method for the reversal of linked list
		// void reverseList(){
		// 	Node* prev = nullptr;
		// 	Node* current = head;
		// 	Node* next = nullptr;
		// 	while(current != nullptr){
		// 		next = current->next;
		// 		current->next = prev;

		// 		prev = current;
		// 		current = next;
		// 	}
		// 	head = prev;
		// };
// Iterative method for the reversal of linked list
void reverse (){
	if (head == nullptr){
		return;
	}
	head = reversalRecursive(head);
}
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
	std::cout<<"\nfirst Print list initializing\n";
	list.printList();
	list.insert(1,7);
	std::cout<<"\nsecond Print actual insertion at index 1\n";
	list.printList();
	list.insert(2,10);
	std::cout<<"\nthird Print actual insertion at index 2\n";
	list.printList();
	list.deleteNode(2);
	std::cout<<"\nfourth Print deltion at index 2\n";
	list.printList();
	list.deleteNode(0);
	std::cout<<"\nfifth Print deltion at head\n";
	list.printList();
	list.reverse();
	std::cout<<"\nSixth Print reverse lsit\n";
	list.printList();

	// list.reversalRecursive(head);
}