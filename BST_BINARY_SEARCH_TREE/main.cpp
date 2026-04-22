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
                    std::cout<<'/nValue Already exists';
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
    
};