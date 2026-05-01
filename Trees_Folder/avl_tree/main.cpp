#include <iostream>

struct Node{
    int data;
    int  height;
    Node* left;
    Node* right;

    Node(int num):data(num), left(nullptr), right(nullptr), height(1){};
};

class Avl{
    private:
        Node* root=nullptr;

        int getHeight(Node* node){
            if(node == nullptr){
                return 0;
            }else{
                return node->height;
            }
        };

        void updateHeight(Node* node){
            if(node != nullptr){
                node->height = 1+std::max(getHeight(node->left),getHeight(node->right));
            };
        };

        int getBalance(Node* node){
            if(node == nullptr){
                return 0;
            }        
            return getHeight(node->left)-getHeight(node->right);
        };

        Node* roatetRight(Node* y){
            Node* x = y->left;
            Node* z = x->right;

            x->right = y;
            y->left = z;

            updateHeight(y);
            updateHeight(x);
            return x;
        };

        Node* rotateLeft(Node* y){
            Node* x = y->right;
            Node* z = x->left;

            x->left = y;
            y->right = z;

            updateHeight(y);
            updateHeight(x);

            return x;
        }


        // void nodeRotation(Node*& temp, int num){
        //     if(root == nullptr){
        //         return;
        //     }else{
        //         Node* tempPointer = root;
        //         if(tempPointer->data>num){
        //             nodeRotation(tempPointer->left, num);
        //         }else if(tempPointer->data == num){
        //             std::cout<<"Can not insert a duplicate entry";
        //             return;
        //         }else{
        //             nodeRotation(tempPointer->right,num);
        //         }
        //     };
        // };

    public:
        // void insert(int num){
        //     Node* newNode = new Node(num);
        //     if(root == nullptr){
        //         root = newNode;
        //     }else if(root != nullptr){
        //         nodeRotation(newNode, num);
        //     };
        // };
        
};