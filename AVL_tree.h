#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>

template<class T>
class AvlTree:{    
    public:
    bool find(const T& t) const{
        find(t, root);
    }
    void midorder() const{
        midorder(root);
    }
    void insert(const T& t){
        insert(t, root);
    }
    void remove(const T& t){
        remove(t, root);
    }
    private:

    struct AvlNode{
        T data;
        AvlNode *right, *left;
        int hight;
        AvlNode(const T& t, AvlNode* l, AvlNode* r):
        data(t),left(nullptr),right(nullptr){

        }
        ~AvlNode(){

        }
    };

    AvlNode* root;
    int max(int a, int b){
        return a>b? a:b;
    }
    int get_hight(const AvlNode* node) const;
    void insert(const T& t, AvlNode* &node);
    void remove(const T& t, AvlNode* &node);
    bool find(const T& t, const AvlNode* node) const; //方便递归
    void midorder(const AvlNode* node) const; //方便递归
    void LL(AvlNode* &node);
    void RR(AvlNode* &node);
    void LR(AvlNode* &node){
        RR(node->left);
        LL(node);
    }
    void RL(AvlNode* &node){
        LL(node->right);
        RR(node);
    }

};

template<class T>
void AvlTree<T>::midorder(const AvlNode* node) const{
    if(node->left != nullptr) midorder(node->left);
    std::cout << node->data << std::endl;
    if(node->right != nullptr) midorder(node->right); 
}

template<class T>
bool AvlTree<T>::find(const T& t, const AvlNode* node) const{
    if(node == nullptr) return 0;
    if(node->data == t) return 1;
    if(node->data > t) return find(node->left);
    return find(node->right);
}

template<class T>
void AvlTree<T>::insert(const T& t, AvlNode* &node){
    int h; //递归调用太多了
    if(t > node->data){
        if(node->right == nullptr){
            node->right = new AvlNode(t, nullptr, nullptr);
        }
        else{
            insert(t, node->right);
        }
        //若进入下面循环则说明第一个失衡节点时在进行了右边插入
        h = get_hight(node->left) - get_hight(node->right);
        switch (h)
        {
        case 2:
            LR();
            break;
        
        case -2:
            RR();
            break;
        }
    }


    if(t < node->data){
        if(node -> left == nullptr){
            node->left == new AvlNode(t, nullptr, nullptr);
        }
        else{
            insert(t, node->left);
        }
        
        h = get_hight(node->left) - get_hight(node->right);
        
        switch (h)
        {
        case 2:
            LL()
            break;
        
        case -2:
            RL();
            break;
        }
    }
    node->hight = max(get_hight(node->right), get_hight(right->left))+1;//是不是每一步都要更新？？//还要注意如果节点存在树中是，不需要调用//
}

template<class T>
int AvlTree<T>::get_hight(const AvlNode* node) const{
    if(node == nullptr) return -1;
    return node->hight;
}

template<class T>
void AvlTree<T>::LL(AvlNode* &node){
    AvlNode* q = node;
    node = node->left;
    q->left = node-> right;
    node->right = q;
    q->hight = max(get_hight(q->left), get_hight(q->right))+1;
    node->hight = max(get_hight(node->left), get_hight(node->right))+1;//更新高度。
}

template<class T>
void AvlTree<T>::RR(AvlNode* & node){
    AvlNode* q = node;
    node = node->right;
    q->right = node->left;
    node -> left = q;
    q->hight = max(get_hight(q->left), get_hight(q->right))+1;
    node->hight = max(get_hight(node->right), get_hight(node->left))+1;
}



#endif
