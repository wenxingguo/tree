#ifndef BSEARCHTREE_H_
#define BSEARCHTREE_H_
#include <iostream>
template <class T>
class BinarySearchTree{
    public:
    
    bool find(const T& t) const{
        return find(t, root);
    }

    void remove(T& t){
        remove(t, root);
    }

    void insert(T& t){
        insert(t, root);
    }

    void midorder(){
        midorder(root);
    }

    void reverse_midorder(){
        reverse_midorder(root);
    }

    BinarySearchTree():root(nullptr){

    }

    protected:
    struct BinaryNode{
        T data;
        BinaryNode *left, *right;
        BinaryNode(const T& t, BinaryNode* lt, BinaryNode* rt):
        data(t), left(lt),right(rt){
        }

        ~BinaryNode(){
            
        }
    };
    BinaryNode* root;
    bool find(const T& t, BinaryNode* node) const;
    void midorder(const BinaryNode* node) const;
    void reverse_midorder(const BinaryNode* node) const;

    private:
    void insert(const T& t, BinaryNode* &node); //一定要使用指针的引用
    //主要在于将指针引用传递进来方便。
    void remove(const T& t, BinaryNode* &node);

};

template<class T>
void BinarySearchTree<T>::insert(const T& t, BinaryNode* &node){
    if(node == nullptr){
        node = new BinaryNode(t, nullptr, nullptr);
        return;
    }
    if(t == node->data) return;
    if(t < node->data) insert(t, node -> left);
    if(t > node-> data) insert(t, node -> right);
}

template<class T>
void BinarySearchTree<T>::remove(const T& t, BinaryNode* &node){
    if(node == nullptr) return;
    if(t < node->data) remove(t, node->left);
    if(t > node ->data) remove(t, node->right);
    if(t == node ->data){
        if(!node->left && !node->right){ //没有儿子
            delete node;
            node = nullptr;
        }
        else{
            if(node->left && node -> right){ // 有两个儿子
                BinaryNode* tmp = node->right;
                while(tmp -> right != nullptr){
                    tmp = tmp->right;
                }
                node->data = tmp -> data;
                remove(tmp->data, node -> right);
            }
            else{
                BinaryNode* oldnode = node;
                node = node->left? node->left:node->right;
                delete oldnode;
            }
        }
    }
}

template<class T>
bool BinarySearchTree<T>::find(const T& t, BinaryNode* node) const{
    if(node == nullptr) return false;
    if(t == node->data) return true;
    if(t < node -> data) return find(t, node->left);
    else{
        return find(t, node -> right);
    }
}

template <class T>
void BinarySearchTree<T>::midorder(const BinaryNode* node) const{
    if(node -> left) midorder(node->left);
    std::cout << node ->data << std::endl;
    if(node -> right) midorder(node -> right);
}

template<class T>
void BinarySearchTree<T>::reverse_midorder(const BinaryNode* node) const{
    if(node->right) reverse_midorder(node -> right);
    std::cout << node->data << std::endl;
    if(node -> left) reverse_midorder(node->left);
}


#endif