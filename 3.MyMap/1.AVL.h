/*************************************************************************
	> File Name: 1.AVL.h
	> Author: 
	> Mail: 
	> Created Time: 2019年11月13日 星期三 13时39分02秒
 ************************************************************************/

#ifndef _AVL_H
#define _AVL_H

#include <iostream>
using namespace std;

template<class K, class V>
class AVLNode {
public:
    AVLNode<K, V> *lchild;
    AVLNode<K, V> *rchild;
    pair<K, V> data;
    int h;
    //AVLNode() : lchild(nullptr), rchild(nullptr), data(nullptr), h(0){}
    AVLNode(const K &key = K(), const V &value = V()) : lchild(nullptr), rchild(nullptr), data(key, value), h(0) {}
};

template<class K, class V>
class AVLTree<K, V> {

typedef AVLNode<K, V> Node;

private:
    Node *root;

public:
    AVLTree();
    void insert(pair<K, V> &data);
    void erase(pair<K, V> &data);
    void output();
    void clear();
    ~AVLTree();

private:
    Node *getNewNode(pair<K, V> &data);
    void UpdateHeight();
    Node *left_rotate();
    Node *right_rotate();
    Node *maintain();
    Node *predeccessor();
    Node *_insert(Node *tree, pair<K, V> &data);
    Node *_erase(Node *tree, pair<K, V> &data);
    void _output(Node *tree);
    void _clear(Node *tree);
};

#endif
