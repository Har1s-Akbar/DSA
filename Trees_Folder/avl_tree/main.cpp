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

        Node* rotateRight(Node* y){
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


        Node* insertionHandle(Node* node, int key){
            if(key>node->data){
                node->right = insertionHandle(node->right,key);
            }
            else if(key<node->data){
                node->left = insertionHandle(node->left,key);
            }else{
                std::cout<<"\nkey already exists\n";
                return node;
            }

            updateHeight(node);
            int balance = getBalance(node);

            if(balance>1 && key > node->data){
                return rotateRight(node);
            };

            if(balance<-1&& key < node->data){
                return rotateLeft(node);
            }

            if(balance>1 && key> node->left->data){
                node->left = rotateLeft(node);
                return rotateRight(node);
            };

            if(balance<1 && key <node->right->data){
                node->right = rotateRight(node);
                return rotateLeft(node);
            }


        };

    public:
        void insert(int num){
            Node* newNode = new Node(num);
            if(root == nullptr){
                root = newNode;
            }else if(root != nullptr){
                insertionHandle(newNode, num);
            };
        };
        
};