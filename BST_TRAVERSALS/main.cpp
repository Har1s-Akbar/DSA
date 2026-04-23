#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int num):data(num), left(nullptr), right(nullptr){};
};

class BST{
    private:
    Node* root = nullptr;

    void clear(Node* node){
        if(node != nullptr){
            clear(node->left);
            clear(node->right);
            delete node;
        };
    };

    void calcPreOrder(Node* node){
        if(node != nullptr){
            std::cout<<" "<<node->data<<" ";
            calcPreOrder(node->left);
            calcPreOrder(node->right);
        }else{
            return;
        }
    };
    public:
    void insert(int num){
        Node* newNode = new Node(num);

        if(root == nullptr){
            root = newNode;
        }else{
            Node* temp =  root;
            Node* tempParent = nullptr;
            while(temp != nullptr){
                tempParent = temp;
                if(num> temp->data){
                    temp = temp->right;
                }else if(num == temp->data){
                    std::cout<<"\nValue Already exist\n";
                    delete newNode;
                    return;
                }else{
                    temp= temp->left;
                }
            };
            if(num > tempParent->data){
                tempParent->right = newNode;
            }else{
                tempParent->left = newNode;
            };
        };
    };

    void search(int num){
        if(root == nullptr){
            std::cout<<"\nTree is empty\n";
        }else{
            Node* temp = root;
            int level = 0;
            while(temp != nullptr && temp->data != num){
                level++;
                if(num>temp->data){
                    temp = temp->right;
                }else if(num == temp->data){
                    std::cout<<"\nRecord Found "<<temp->data<<" at level "<< level;
                    return;
                }else{
                    temp = temp->left;
                }
            };
            std::cout<<"\n Can not find the record \n";
        };
    };

    void preOrder(){
        Node* temp = root;
        calcPreOrder(temp);
    };

    ~BST(){
        Node* temp = root;
        clear(temp);
        root = nullptr;
    };
};

int main(){
    BST tree;
    tree.insert(20);
    tree.insert(25);
    tree.insert(15);
    tree.insert(21);
    tree.insert(9);
    tree.insert(17);
    tree.insert(27);

    std::cout<<"\nPre Order Traversal: ";
    tree.preOrder();


};