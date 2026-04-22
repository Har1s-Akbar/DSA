#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int num): data(num), left(nullptr), right(nullptr){};
};

class BST{
    private:
        Node* root= nullptr;

    void clear (Node* node){
        if(node != nullptr){
            clear(node->left);
            clear(node->right);
            delete node;
        }else{
            return;
        }
    };

    void printInOrder(Node* node){
        if(node != nullptr){
            printInOrder(node->left);
            std::cout<<' '<<node->data<< ' ';
            printInOrder(node->right);
        }else{
            return;
        };
    };

    public:
    void insert(int num){
        Node* newNode = new Node(num);
        if(root == nullptr){
            root = newNode;
        }else{
            Node* temp = root;
            Node* tempParent = nullptr;
            while(temp!= nullptr){
                tempParent = temp;
                if(temp->data > num){
                    temp = temp->left;
                }else if(temp->data == num){
                    std::cout<<'\nValue Already exists';
                    delete newNode;
                    return;
                }else{
                    temp = temp->right;
                };
            };
            if(tempParent->data >num){
                tempParent->left = newNode;
            }else{
                tempParent->right = newNode;
            };
        };
    };
    void search(int num){
        Node* temp =  root;
        int level = 0;
        while(temp!= nullptr && temp->data != num){
            if(temp->data  > num){
                temp= temp->left;
            }else{
                temp= temp->right;
            };
            level++;
        };
        if(temp != nullptr){
            std::cout<<temp->data<<'\n Found at tree level '<<level<<'\n';
        }else{
            std::cout<<'\nRecord not found';
        }
    };
    
    void inOrder(){
        Node* temp = root;
        if(temp == nullptr){
            std::cout<<'\nTree is Empty\n';
        }else{
            printInOrder(temp);
        }
    };

    ~BST(){
        Node* temp = root;
        clear(temp);
        root = nullptr;
    };
};