# include <bit/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int height;
    int key;
    Node(int key){
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->height = 0;
    } 

}

class AVLTree{
    public:
    Node* root;

    int getHeight(Node* node){
        if(node == NULL){
            return 0;
        }
        return node->height;
    }
    int getBalanceFactor(Node* node){
        if(node == NULL){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateLeft(Node* node){
        Node* rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        rightChild->height = max(getHeight(node->left), getHeight(node->left)) + 1;
        
        return rightChild;
    }
    
    Node* rotateRight(Node* node){
        Node* leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        leftChild->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        
        return leftChild;
    }

    Node* insertNode(Node* node, int key){
        if(node == NULL){
            return new Node(key);
        }
        if(key < node->key){
            node->left = insertNode(node->left, key);
        } else {
            node->right = insertNode(node->right, key);
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balanceFactor = getBalanceFactor(node);
        if(balanceFactor > 1){
            if(key < node->left->key){
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        } else if(balanceFactor < -1){
            if(key > node->right->key){
                return roatateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;

    }
}



int main(){
    return 0;

}