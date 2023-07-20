// Rules for a tree to be a Red Black Tree
// The root node is always a black node
// All the nodes should be either be red or black
// No two consecutive red nodes can occur together 
// The number of black nodes from the root node to the leaf node must be equal
// Null nodes will be treated as black;
// The new insertions done to the Red-Black Tree will be node with the color value of Red






// # include <bits/stdc++.h>
// enum class Color {red, black};

// class Node {
//     int key;
//     Node* left;
//     Node* right;
//     Node* parent;
//     Color color;

//     public :
//     Node(int key){
//         this->key = key;
//         this->left = NULL;
//         this->right = NULL;
//         this->parent = NULL;
//         this->color = Color::red;
//     }
// };

// class RedBlackTree{
//     Node* root;

//     void rotateLeft(Node* node){
//         Node* rightChild = node->right;
//         node->right = rightChild->left;
//         rightChild->left->parent = node;

//         if(node->parent == NULL){
//             root = rightChild;
//         } else if(node == node->parent->left){
//             node->parent->left = rightChild;
//         } else {
//             node->parent->right = rightChild;
//         }
//         rightChild->left = node;
//         node->parent = rightChild;
//     }

//     void rotateRight(Node* node){
//         Node* leftChild = node->left;
//         node->left = leftChild->right;
//         leftChild->right->parent = node;

//         if(node->parent == NULL){
//             root = leftChild;
//         } else if (node == node->parent->right){
//             node->parent->right = leftChild;
//         } else {
//             node->parent->left = leftChild;
//         }
//         leftChild->right = node;
//         node->parent = leftChild;
//     }

//     void fixInsert(Node* node){
//         while(node != root && node->parent->color == Color::red){
//             if(node->parent == node->parent->parent->left){
//                 Node* aunt = node->parent->parent->right;
//                 if(aunt != NULL && aunt->color == Color::red){
//                     node->parent->parent->color = Color::red;
//                     node->parent->color = Color::black;
//                     aunt->color = Color::black;
//                     node = node->parent->parent;
//                 } else {
//                     if(node == node->parent->right){
//                         node = node->parent;
//                         rotateLeft(node);
//                     }
//                     node->parent->color = Color::black;
//                     node->parent->parent->color = Color::red;
//                     rotateRight(node->parent->parent);
//                 }
//             } else {
//                 Node* aunt = node->parent->parent->left;
//                 if(aunt != NULL && aunt->color == Color::red){
//                     node->parent->parent->color = Color::red;
//                     node->parent->color = Color::black;
//                     aunt->color = Color::black;
//                     node = node->parent->parent;
//                 } else {
//                     if(node == node->parent->left){
//                         node = node->parent;
//                         rotateRight(node);
//                     }
//                     node->parent->color = Color::black;
//                     node->parent->parent->color = Color::red;
//                     rotateLeft(node);

//                 }
//             }

//         }
//         root->color = Color::black;
//     }
// };


# include <bits/stdc++.h>
using namespace std;

enum Color {red, black} ; 

class Node{
    public:
    Node* parent;
    Node* left;
    Node* right;
    int key;
    Color color;
    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
        this->color = Color::red;
    }
};

class RedBlackTree{
    public:
    Node* root;

    void rotateLeft(Node* node){
        Node* rightChild = node->right;
        node->right = rightChild->left;
        if (rightChild->left != NULL){
            rightChild->left->parent = node;
        }
        rightChild->parent = node->parent;
        if(node->parent == NULL){
            root = rightChild;
        } else if(node == node->parent->left){
            node->parent->left = rightChild;
        } else {
            node->parent->right = rightChild;
        }
        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node* node){
        Node* leftChild = node->left;
        node->left = leftChild->right;
        if(leftChild->right != NULL){
            leftChild->right->parent = node;
        }
        leftChild->parent = node->parent;
        if(node->parent == NULL){
            root = leftChild;
        } else if(node == node->parent->right){
            node->parent->right = leftChild;
        } else {
            node->parent->left = leftChild;
        }
        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixInsert(Node* node){
        while(node != root && node->parent->color == Color::red){
            if(node->parent == node->parent->parent->right){
                Node* aunt = node->parent->parent->left;
                if(aunt != NULL && aunt->color == Color::red){
                    node->parent->parent->color = Color::red;
                    node->parent->color = Color::black;
                    aunt->color = Color::black;
                    node = node->parent->parent;
                } else {
                    if(node == node->parent->left){
                        node = node->parent;
                        rotateRight(node);
                    }
                    node->parent->color = Color::black;
                    node->parent->parent->color = Color::red;
                    rotateLeft(node->parent->parent);
                }
            } else {
                Node* aunt = node->parent->parent->right;
                if(aunt != NULL && aunt->color == Color::red){
                    node->parent->parent->color = Color::red;
                    node->parent->color = Color::black;
                    aunt->color = Color::black;
                    node = node->parent->parent;
                } else {
                    if(node == node->parent->right){
                        node = node->parent;
                        rotateLeft(node);
                    }
                    node->parent->color = Color::black;
                    node->parent->parent->color = Color::red;
                    rotateRight(node->parent->parent);
                }

            }

        }
        root->color = Color::black;
    }

    RedBlackTree(){
        this->root = NULL;
    }

    void insert(int key){
       Node* newNode = new Node(key); 
       if(root == NULL){
        root = newNode;
        root->color = Color::black;
        return;
       }
       Node* current = root;
       Node* parent = NULL;
       while(current != NULL){
        parent = current;
        if(key < current->key){
            current = current->left;
        } else {
            current = current->right;
        }
       }
       newNode->parent = parent;
       if(key < parent->key){
        parent->left = newNode;
       } else {
        parent->right = newNode;
       }

       fixInsert(newNode);
    }

    void printTree(){
        if(root == NULL){
            cout<<"The tree is empty"<<endl;
            return;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
                Node* temp = q.front();
                cout<<temp->key<<"("<<temp->color<<")"<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
        }
    }
};


int main(){
    RedBlackTree* rb = new RedBlackTree();
    rb->insert(1);
    rb->insert(3);
    rb->insert(4);
    rb->printTree();
}