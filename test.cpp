#include "bsearchtree.h"
#include<iostream>
using namespace std;
int main(){
    double h[7] = {10.1,4.9,6,8,9,7,11};
    //cout << "Enter number : "; 
    //cin >> g;
    BinarySearchTree<double> tree;

    for(int i = 0; i < 7; ++i){
        tree.insert(h[i]);
    }
    tree.reverse_midorder();
}