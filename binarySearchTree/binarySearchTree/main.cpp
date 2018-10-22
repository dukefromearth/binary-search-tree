//Stephen Duke

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "BST.hpp"

int main(){
    using namespace std::chrono;
    AVL<int> myAVL1;
    BST<int> myBST1;
    AVL<int> myAVL2;
    BST<int> myBST2;
    AVL<int> myAVL3;
    BST<int> myBST3;
    
    cout << "Stephen Duke" << endl;
    
    std::vector<int> vec;
    for (int i = 0; i < 20; ++i){
        double num = rand() % 100;
        vec.push_back(num);
    }
    
    vec = {40,30,19,1,3,100,54,88,92};
    
    auto t1 = chrono::steady_clock::now();
    //insert 10000
    for (int i = 0; i < 9; ++i){
        myBST1.Insert(vec[i]);
    }
    cout << myBST1.Size() << endl;
    //remove every other
    for (int i = 0; i < 9; i=i+2){
        myBST1.Remove(vec[i]);
    }
    auto t2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << endl;
    
    
    t1 = chrono::steady_clock::now();
    //insert 10000
    for (int i = 0; i < 9; ++i){
        myAVL1.Insert(vec[i]);
    }

    cout << myAVL1.Size() << endl;
    //remove every other
    for (int i = 0; i < 9; i=i+2){
        myAVL1.Remove(vec[i]);
    }
    t2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << endl;

    
    t1 = chrono::steady_clock::now();
    //insert 10000
    for (int i = 0; i < 100000; ++i){
        myBST2.Insert(vec[i]);
    }

    //remove every other
    for (int i = 0; i < 100000; i=i+2){
        myBST2.Remove(vec[i]);
    }
    t2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << endl;


    t1 = chrono::steady_clock::now();
    //insert 10000
    for (int i = 0; i < 100000; ++i){
        myAVL2.Insert(vec[i]);
    }

    //remove every other
    for (int i = 0; i < 100000; i=i+2){
        myAVL2.Remove(vec[i]);
    }
    t2 = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << endl;


//
//
//
//
//    t1 = chrono::steady_clock::now();
//    //insert 10000
//    for (int i = 0; i < 1000000; ++i){
//        myBST3.Insert(vec[i]);
//    }
//
//    //remove every other
//    for (int i = 0; i < 1000000; i=i+2){
//        myBST3.Remove(vec[i]);
//    }
//    t2 = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << endl;
//
//
//    t1 = chrono::steady_clock::now();
//    //insert 1000000
//    for (int i = 0; i < 1000000; ++i){
//        myAVL3.Insert(vec[i]);
//    }
//
//    //remove every other
//    for (int i = 0; i < 1000000; i=i+2){
//        myAVL3.Remove(vec[i]);
//    }
//    t2 = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << endl;
}
