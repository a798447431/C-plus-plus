/*************************************************************************
	> File Name: 1.hashtable.h
	> Author: 
	> Mail: 
	> Created Time: 2019年10月26日 星期六 16时39分09秒
 ************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
#define MAX_STR 1024

class HashFunc {
public :
    virtual int operator() (const void *value) = 0;
     //~HashFunc();
};

typedef struct Node {
    int ind;
    char str[MAX_STR + 5];
} Node;

class HashTable {
public :
    HashTable(HashFunc &hf, int num) : _hf(&hf), _num(num) {
        data = (Node *)malloc(sizeof(Node) * num);
    }
    int insert(const void *str, int num) {
        _num = num;
        if (_hf == nullptr) return 0;
        int hash = (*_hf)(str);
        int ind = hash % num;
        data[hash].ind++;
        memcpy(data[ind].str, data, sizeof(char) * MAX_STR);
        return ind;
    }
    bool find(const void *str, int num) {
        _num = num;
        if (_hf == nullptr) return false;
        int hash = (*_hf)(str);
        int ind = hash % num;
        if (data[ind].ind) return true;
        else return false;
    };
    ~HashTable() {
        delete[] data;
    }

private :
    Node *data;
    HashFunc *_hf;
    int _num;
};

