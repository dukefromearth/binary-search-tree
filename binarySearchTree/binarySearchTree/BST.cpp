//Stephen Duke

#include "BST.hpp"
#include <stack>
#include <utility>

template <typename Type>
bool isLessThan(Type l, Type r){
    if(l.data < r.data) return true;
    else return false;
}

template <typename Type>
Node<Type> *findMin(Node<Type> *root){
    if (!root) return nullptr;
    if (!root->left) return root;
    return findMin(root->left);
}

template <typename Type>
Node<Type> *findMax(Node<Type> *root){
    if (root) {
        while (root->right){
            root = root->right;
        }
    }
    return root;
}

template <typename Type>
void BST<Type>::insert(Node<Type> *&root, const Type &data) {
    if(!root) {
        root = new Node<Type>(std::move(data));
    } else if(data < root->data){
        insert(root->left, std::move(data));
    } else if(data > root->data){
        insert(root->right, std::move(data));
    }
}
    
template <typename Type>
void BST<Type>::remove(Node<Type> *&root, const Type &data){
    if(!root) return;
    if (data < root->data){
        remove(root->left, data);
    }else if(data > root->data){
        remove(root->right, data);
    }else if(root->left && root->right){
        root->data = findMin(root->right)->data;
        remove(root->right,root->data);
    }else{
        Node<Type> *nodeToDelete = root;
        if(root->left) root = root->left;
        else root = root->right;
        delete nodeToDelete;
    }
}

template <typename Type>
void BST<Type>::print(Node<Type> *root){
    if(root){
        if (root->left) print(root->left);
        cout << root->data;
        if (root->right) print(root->right);
    }
}

template <typename Type>
void BST<Type>::clearAll(Node<Type> *&root){
    if(root){
        if (root->left) clearAll(root->left);
        if (root->right) clearAll(root->right);
        delete root;
    }
    root = nullptr;
}

class badAccess{
    virtual const char* what() const throw() {
        return "bad access!";
    }
} badAccess;

template <typename Type>
Type BST<Type>::operator[](int num){
    std::stack<Node<Type> *> s;
    Node<Type> *curr = root;
    int count = 0;
    
    while(curr || !s.empty()){
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if(count == num) return curr->data;
        else count ++;
        
        curr = curr->right;
    }
    try{
        throw badAccess;
    } catch(exception& e){
        cout << e.what() << endl;
    }
    return 0;
}

template <typename Type>
Node<Type> *createCopy(Node<Type> *root){
    if(!root) return nullptr;
    else return new Node<Type>(root->data, createCopy(root->left), createCopy(root->right));
}

template <typename Type>
int BST<Type>::size(Node<Type> *root){
    if(!root) return 0;
    else return (size(root->left) + 1 + size(root->right));
}

template <typename Type>
int BST<Type>::height(Node<Type> *root){
    if (!root) return 0;
    else{
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight < rightHeight) return rightHeight + 1;
        else return leftHeight + 1;
    }
}
