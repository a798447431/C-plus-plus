/*************************************************************************
	> File Name: mini_map.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月14日 星期四 19时28分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Node {
public:
    Node();
    Node *lchild();
    Node *rchild();
    void set_lchild(Node *lchild);
    void set_rchild(Node *rchild);   
    virtual ~Node(){}

private:
    Node *_lchild, *_rchild;
};

template<class T>
class DataNode : public Node {
public:
    DataNode(const T &key) : _key(key) {}
    DataNode(const T &&key) : _key(key) {}
    T &key() { return this->_key; }
    static DataNode<T> *getNewNode(const T &key) {
        return new DataNode<T>(key);
    }

private:
    T _key;
};

template<class KEY_T, class VALUE_T>
class BSTree {
public:
    typedef pair<KEY_T, VALUE_T> Data;
    typedef DataNode<pair<KEY_T, VALUE_T> > BSNode;
    BSTree() : root(nullptr) {}
    void insert(const Data &val);
    const VALUE_T &query(const KEY_T &val);

private:
    BSNode *root;
    VALUE_T _end;
};

typedef pair<int, int> PII;

int main() {
    BSTree<int ,int > b;
    b.insert(PII(123, 45));
    b.insert(PII(45, 123));
    cout << b.query(123) << endl;
    cout << b.query(45) << endl;
    cout << b.query(99) << endl;
    return 0;
}
 
Node::Node() : _lchild(nullptr), _rchild(nullptr){}

Node *Node::lchild() { return this->_lchild; }

Node *Node::rchild() { return this->_rchild; }

void Node::set_lchild(Node *lchild) {
    this->_lchild = lchild;
    return ;
}

void Node::set_rchild(Node *rchild) {
    this->_rchild = rchild;
    return ;
}

template<class T, class U>
void BSTree<T, U>::insert(const Data &val) {
    BSNode *p = root;
    if (p == nullptr) {
        root = BSNode::getNewNode(val);
        return ;
    }
    do {
        if (val.first < p->key().first) {
            if (p->lchild()) p = dynamic_cast<BSNode *>(p->lchild());
            else p->set_lchild(BSNode::getNewNode(val));
        } else if (p->key().first < val.first) {
            if (p->rchild()) p = dynamic_cast<BSNode *>(p->rchild());
            else p->set_rchild(BSNode::getNewNode(val));
        } else {
            return ;
        } 
    } while (1);
    return ;
}

template<class T, class U>
const U &BSTree<T, U>::query(const T &val) {
    BSNode *p = root;
    while (p) {
        if (p->key().first < val) {
            p = dynamic_cast<BSNode *>(p->rchild());
        } else if (val < p->key().first) {
            p = dynamic_cast<BSNode *>(p->lchild());
        } else return p->key().second;
    }
    return _end;
}
