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

        Node* catchImbalance(Node*& temp){
            if(temp == nullptr){
                return nullptr;
            }else{
                Node* imbNode = catchImbalance(temp->left);
                
            }
        };
        void nodeRotation(Node*& temp){
            Node* imbalancedNode = catchImbalance(temp);
        };

    public:
        void insert(int num){
            Node* newNode = new Node(num);
            if(root == nullptr){
                root = newNode;
            }else if(root != nullptr){
                Node* temp = root;
                while(temp!= nullptr){
                    if(temp->data > num){
                        temp = temp->left;
                    }else if(temp->data == num){
                        std::cout<<"Can not insert Duplicates";
                        delete newNode;
                        return;
                    }else{
                        temp = temp->right;
                    }
                }
            };

            Node* temp = root;
            nodeRotation(temp);

        };
        
};