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
            std::cout<<" "<<node->data;
            calcPreOrder(node->left);
            calcPreOrder(node->right);
        }
    };

    void calcInOrder(Node* node){
    if(node != nullptr){
        calcInOrder(node->left);
        std::cout<<" "<<node->data;
        calcInOrder(node->right);
    }
    };

    void calcPostOrder(Node* node){
        if(node != nullptr){
            calcPostOrder(node->left);
            calcPostOrder(node->right);
            std::cout<<" "<<node->data;
        }
    }

    bool calcIsBst(Node* node, int*& prev){
        if(node == nullptr){
            return true;
        };
        if(!calcIsBst(node->left, prev)){
            return false;
        }

        if(prev!= nullptr && node->data <=*prev){
            return false;
        }

        prev = &node->data;

        return calcIsBst(node->right, prev);
    }

    void handleDelete(Node*& node, int num){
        if(node != nullptr){
            if(node->data > num){
                handleDelete(node->left, num);
            }else{
                handleDelete(node->right, num);
            }
            if(node->data == num){
                if(node->left == nullptr && node->right == nullptr){
                    delete node;
                    node = nullptr;
                }else if(node ->left == nullptr || node->right == nullptr){
                    if(node->left != nullptr){
                        Node* nodeDelete = node;
                        node = node->left;
                        delete nodeDelete;
                    }else if(node->right != nullptr){
                        Node* nodeDelete = node;
                        node = node->right;
                        delete nodeDelete;
                    }
                }else{
                    Node* temp = node->right;
                    while(temp->left != nullptr){
                        temp= temp->left;
                    };
                    node->data = temp->data;
                    handleDelete(node->right,node->data);
                }
            };
        }
    }

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
            int level = -1;
            while(temp != nullptr){
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

    void inOrder(){
        Node* temp = root;
        calcInOrder(temp);
    };

    void postOrder(){
        Node* temp = root;
        calcPostOrder(temp);
    };

    bool isBST(){
        Node* temp = root;
        int* prev = nullptr;
        return calcIsBst(temp , prev);
    };

    void deleteNode(int num){
        handleDelete(root, num);
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

    std::cout<<"\nIn Order Traversal: ";
    tree.inOrder();

    std::cout<<"\nPost Order Traversal: ";
    tree.postOrder();    

    int search;
    std::cout<<"\nWhat do you want to search in the tree\n";
    std::cin>>search;
    std::cout<<"\nSearching for the record ";
    tree.search(search);

    std::cout<<"\nchecking if tree is BST "<<tree.isBST();

    
};