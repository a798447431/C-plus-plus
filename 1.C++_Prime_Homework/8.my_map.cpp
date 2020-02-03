/*************************************************************************
	> File Name: 8.my_map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月12日 星期二 18时20分24秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

template<class K, class V>
struct AVLNode {
    AVLNode<K, V> *lchild;
    AVLNode<K, V> *rchild;
    pair<K, V> data;
    int h;
    AVLNode(const K& key = K(), const V& value = V()) : lchild(nullptr), rchild(nullptr), data(k, v), h(0){}
};

template<class K, te V>
struct AVL {
    typedef AVLNode<K, V> Node;
public:
    Node *getNewNode(pair<K, V> &key) {
        Node *p = new Node;
        p->key = key;
        p->lchild = p->rchild = nullptr;
        return p;
    }
    Node *insert(pair<K, V> &key) {
        if (root == nullptr) return getNewNode(key);
        if (root->key.first == key.first) return root;
        if (root->key.first > key.first) root->lchild = insert(root->lchild, key);
        else root->rchild = insert(root->rchild, key);
        return root;
    }
    Node *predecessor() {
        Node *temp = root->lchild;    
        while (temp->rchild) temp = temp->rchild;
        return temp;
    }
    Node *erase(pair<K, V> &key) {
        if (root == nullptr) return root;
        if (root->key.first > key.first) root->lchild = erase(root->lchild, key);
        else if (root->key.first < key.first) root->rchild = erase(root->rchild, key);
        else {
            if (root->lchild == nullptr || root->rchild == nullptr) {
                Node *temp = root->lchild ? root->lchild : root->rchild;
                delete root;
                return temp;
            } else {
                Node *temp = predecessor(root);
                root->key = temp->key;
                root->lchild = erase(root->lchild, temp->key);
            }
        }
        return root;
    }
    bool Empty() {
        return root == nullptr;    
    }

private:
    Node *root;
};

template<typename K, typename V>
struct map {
public:
    map() : _bst(){}
    void insert(const pair<K, V> &key) {
        _bst.insert(key);
    }
    void erase(const pair<K, V> &key) {
        _bst.erase(key);
    }
    bool Empty() const {
        return _bst.Empty();
    }
    V& operator[](const K& k) {
        _bst.insert(pair<K, V>(key, V).first;
    }

private:
    BST<K, V> _bst;
};


int main() {

    return 0;
}
