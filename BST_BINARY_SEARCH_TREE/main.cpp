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
    void search(int num){
        Node* temp =  root;
        Node* tempParent = nullptr;
        int level = 0;
        while(temp->data != num && temp!= nullptr){
            tempParent = temp;
            if(temp->data  > num){
                temp= temp->right;
            }else{
                temp= temp->left;
            };
            level++;
        };
        if(tempParent->left != nullptr || tempParent ->right != nullptr){
            std::cout<<tempParent->data<<'/n Found at tree level '<<level<<'/n';
        }else{
            std::cout<<'/nRecord not found';
        }
    };
};