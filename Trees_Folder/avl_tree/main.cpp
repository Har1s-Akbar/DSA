#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int num):data(num), left(nullptr), right(nullptr){};
};

class Avl{
    private:
        Node* root=nullptr;

        void nodeRotation(Node*& temp, int num){
            if(root == nullptr){
                return;
            }else{
                Node* tempPointer = root;
                if(tempPointer->data>num){
                    nodeRotation(tempPointer->left, num);
                }else if(tempPointer->data == num){
                    std::cout<<"Can not insert a duplicate entry";
                    return;
                }else{
                    nodeRotation(tempPointer->right,num);
                }
            };
        };

    public:
        void insert(int num){
            Node* newNode = new Node(num);
            if(root == nullptr){
                root = newNode;
            }else if(root != nullptr){
                nodeRotation(newNode, num);
            };
        };
        
};