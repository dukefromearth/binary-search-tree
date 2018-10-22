//Stephen Duke

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

#include <iostream>
using namespace std;


template <typename Type>
struct Node {
    Type data;
    Node* left;
    Node* right;
    
    Node(Type value): data(value), left(nullptr), right(nullptr) {}
    Node(Type value, Node<Type> *l, Node<Type> *r) : data(value), left(l), right(r) {}
};

template<typename Type>
class BST{
public:
    BST<Type>() : root(nullptr) {} //initiates to null
    ~BST<Type>() { clearAll(root); } //deletes every node
    BST<Type>(BST<Type> &copy) {root = createCopy(copy.root);} //copy constructor
    void Insert(const Type &data) { insert(root,data); }
    void Remove(const Type &data) { remove(root,data); }
    void Print() { print(root); }
    int Size() { return size(root); }
    int Height() { return height(root); }
    Type operator[](int num);
    
protected:
    Node<Type> *root;
    void insert(Node<Type> *&root, const Type &data);
    void remove(Node<Type> *&root, const Type &data);
    void print(Node<Type> *root);
    int size(Node<Type> *root);
    int height(Node<Type> *root);
    void clearAll(Node<Type> *&root);
    
    friend Node<Type> *createCopy(Node<Type> *root);
    friend bool isLessThan(Type l, Type r);
    friend Node<Type> *findMin(Node<Type> *root);
    friend Node<Type> *findMax(Node<Type> *root);
    
    
};


template<typename Type>
class AVL: public BST<Type> {
public:
    void Insert(const Type &data) { insert(this->root, data); }
    
private:
    Node<Type> *rotateRight(Node<Type> *&root){
        Node<Type> *rootLR = root->left->right;
        Node<Type> *newRoot = root->left;
        
        root->left = rootLR;
        newRoot->right = root;
        
        return newRoot;
    }
    Node<Type> *rotateLeft(Node<Type> *&root){
        Node<Type> *rootRL = root->right->left;
        Node<Type> *newRoot = root->right;
        
        root->right = rootRL;
        newRoot->left = root;
        
        return newRoot;
    }
    int getBalance(Node<Type> *root){
        if (!root) return 0;
        else return this->height(root->left) - this->height(root->right);
    }
    void insert(Node<Type> *&root, const Type &data){
        if(!root) {
            root = new Node<Type>(std::move(data));
        }
        if (data < root->data){
            insert(root->left, data);
            return;
        } else if (data > root->data){
            insert(root->right,data);
            return;
        }
        
        //left left
        if(getBalance(root) > 1 && data < root->left->data){
            root = rotateRight(root);
        }
        
        //right right
        if(getBalance(root) < -1 && data > root->right->data){
            root = rotateLeft(root);
        }
        
        //left right
        if (getBalance(root) > 1 && data > root->left->data){
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
        
        //right left
        if (getBalance(root) < -1 && data < root->right->data){
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
        
    }
    
};


#include "BST.cpp"
#endif /* BST_hpp */
