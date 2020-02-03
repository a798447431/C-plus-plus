/*************************************************************************
	> File Name: other_AVL.h
	> Author: 
	> Mail: 
	> Created Time: 2019年11月14日 星期四 15时47分55秒
 ************************************************************************/

#ifndef _OTHER_AVL_H
#define _OTHER_AVL_H

#include <iostream>
using namespace std;

template<class K, class V>
class AVLNode {
public:
    pair<K, V> data;
    int h;
    AVLNode *lchild;
    AVLNode *rchild;
    AVLNode(const K& key, const V& value, AVLNode *l, AVLNode *r) : data(key, value), h(0), lchild(l), rchild(r) {}
};

template<class K, V>
class AVLTree {
private:
    AVLNode<K, V> *mroot;
public:
    AVLTree();
    ~AVLTree();
    int height();
    int max(int a, int b);
    void preorder();
    void inorder();
    void postorder();

    AVLNode<K, V> *search(pair<K, V> data);
    AVLNode<K, V> *iteratorSearch(pair<K, V> data);
    void insert(pair<K, V> data);
    void remove(pair<K, V> data);
    void destroy();
    void print();

private:
    int height(AVLNode<K, V> *tree);
    void preorder(AVLNode<K, V> *tree) const;
    void inorder(AVLNode<K, V> *tree) const;
    void postorder(AVLNode<K, V> *tree) const;
    AVLNode<K, V> *search(AVLNode<K, V> *tree, pair<K, V> data) const;
    AVLNode<K, V> *iteratorSearch(AVLNode<K, V> *tree, pair<K, V> data) const;
    AVLNode<K, V> *leftleft_rotate(AVLNode<K, V> *k2);
    AVLNode<K, V> *rightright_rotate(AVLNode<K, V> *k1);
    AVLNode<K, V> *leftright_rotate(AVLNode<K, V> *k3);
    AVLNode<K, V> *rightleft_rotate(AVLNode<K, V> *k1);
    AVLNode<K, V> *insert(AVLNode<K, V>* &tree, pair<K, V> data) const;
    
};

#endif
