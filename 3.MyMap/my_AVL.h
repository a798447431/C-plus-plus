/*************************************************************************
	> File Name: my_AVL.h
	> Author: 
	> Mail: 
	> Created Time: 2019年11月14日 星期四 10时57分13秒
 ************************************************************************/

#ifndef _MY_AVL_H
#define _MY_AVL_H

#include <iostream>
#include <cstdlib>
using namespace std;

template<class K, class V>
class AVLNode {
public:
    pair<K, V> data; //键值对
    int h; //树高
    AVLNode<K, V> *lchild;
    AVLNode<K, V> *rchild;
    //AVLNode() : lchild(nullptr), rchild(nullptr), data(nullptr), h(0) {}
    AVLNode(const K& key, const V& value) : lchild(nullptr), rchild(nullptr), data(key, value), h(0) {}
    /*
    AVLNode(const AVLNode<K, V> &a) {
        this->lchild = a.lchild;
        this->rchild = a.rchild;
        this->data = a.data;
        this->h = a.h;
    }
    */
};

template<class K, class V>
class AVLTree {
    typedef AVLNode<K, V> Node;
    typedef pair<K, V> Data;

private:
    Node *m_root;

public:
    AVLTree();
    ~AVLTree();
    void insert(Data data);
    void erase(Data data);
    void output();
    void clear();

private:
    Node *getNewNode(Data data);
    void UpdataHeight(Node *root);
    Node *left_rotate(Node *root);
    Node *right_rotate(Node *root);
    Node *maintain(Node *root);
    Node *predeccessor(Node *root);
    Node *_insert(Node* &root, Data data);
    Node *_erase(Node* &root, Data data);
    void _output(Node *root);
    void _clear(Node *root);   
};

template<class K, class V>
AVLTree<K, V>::AVLTree() : m_root(nullptr) {

}

template<class K, class V>
AVLTree<K, V>::~AVLTree() {
    _clear(m_root);
}

template<class K, class V>
void AVLTree<K, V>::insert(pair<K, V> data) {
    m_root = _insert(m_root, data);
}

template<class K, class V>
void AVLTree<K, V>::erase(pair<K, V> data) {
    m_root = _erase(m_root, data);
}

template<class K, class V>
void AVLTree<K, V>::output() {
    _output(m_root);
}

template<class K, class V>
void AVLTree<K, V>::clear() {
    _clear(m_root);
}

template<class K, class V> 
AVLNode<K, V> *AVLTree<K, V>::getNewNode(pair<K, V> data) {
    //AVLNode<K, V> *p = (AVLNode<K, V> *)malloc(sizeof(AVLNode<K, V>));
    AVLNode<K, V> *p = new AVLNode<K, V>(data.first, data.second);
    //p->data = data;
    //p->lchild = p->rchild = nullptr;
    p->h = 1;
    cout << p->data.first << " " << p->data.second << " " << p->h << endl;
    cout << "have get a new node!" << endl;
    return p;
}

template<class K, class V>

void AVLTree<K, V>::UpdataHeight(AVLNode<K, V> *root) {
    int h1 = root->lchild->h;
    int h2 = root->rchild->h;
    root->h = (h1 > h2 ? h1 : h2) + 1;
    return ;
}

template<class K, class V>
AVLNode<K, V> *AVLTree<K, V>::left_rotate(AVLNode<K, V> *root) {
    AVLNode<K, V>* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    UpdataHeight(root);
    UpdataHeight(temp);
    return temp;
}

template<class K, class V>
AVLNode<K, V> *AVLTree<K, V>::right_rotate(AVLNode<K, V> *root) {
    AVLNode<K, V>* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    UpdataHeight(root);
    UpdataHeight(temp);
    return temp;
}

template<class K, class V>
AVLNode<K, V> *AVLTree<K, V>::maintain(AVLNode<K, V> *root) {
    if (abs(root->lchild->h - root->rchild->h) <= 1) return root;
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->rchild->h > root->lchild->lchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->lchild->h > root->rchild->rchild->h) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
    return root;
}

template<class K, class V>
AVLNode<K, V> *AVLTree<K, V>::predeccessor(AVLNode<K, V> *root) {
    AVLNode<K, V> *temp = root->lchild;
    while (temp->rchild != nullptr) temp = temp->rchild;
    return temp;
}

template<class K, class V>
AVLNode<K, V> *AVLTree<K, V>::_insert(AVLNode<K, V>* &root, pair<K, V> data) {
    cout << "inserting" << endl;
    if (root == nullptr) { 
        cout << "inserting is failed!" << endl;
        return getNewNode(data);
    }
    if (root->data.first > data.first) root->lchild = _insert(root->lchild, data);
    else if (data.first > root->data.first) root->rchild = _insert(root->rchild, data);
    else {
        cout << "inserting is already exist!" << endl;
        return root;
    }
    UpdataHeight(root);
    cout << "insert success" << endl;
    return maintain(root);
}

template<class K, class V>
AVLNode<K, V> *AVLTree<K, V>::_erase(AVLNode<K, V>* &root, pair<K, V> data) {
    if (root == nullptr) return root;
    if (root->data.first > data.first) root->lchild = _erase(root->lchild, data);
    else if (data.first > root->data.first) root->rchild = _erase(root->rchild, data);
    else {
        if (root->lchild == nullptr || root->rchild == nullptr) {
            AVLNode<K, V> *temp = (root->lchild == nullptr ? root->rchild : root->lchild);
            delete root;
            return temp;
        } else {
            AVLNode<K, V> *temp = predeccessor(root);
            root->data = data;
            root->lchild = _erase(root->lchild, data);
        }
    }
    UpdataHeight(root);
    return maintain(root);
}

template<class K, class V>
void AVLTree<K, V>::_output(AVLNode<K, V> *root) {
    cout << "outputing" << endl;
    if (root == nullptr) {  
        cout << "root == nullptr" << endl;
        return ;
    }
    _output(root->lchild);
    cout << "key = " << root->data.first << " " << root->data.second << " [" << root->lchild->data.first << " " << root->rchild->data.second << "] [" << root->rchild->data.first << " " << root->rchild->data.second << "]" << endl;
    _output(root->rchild);
    return ;
}

template<class K, class V>
void AVLTree<K, V>::_clear(AVLNode<K, V> *root) {
    if (root == nullptr) return ;
    _clear(root->lchild);
    _clear(root->rchild);
    delete root;
    return ;
}
#endif
