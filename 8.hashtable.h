/*************************************************************************
	> File Name: 8.hashtable.h
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 14时41分23秒
 ************************************************************************/

#ifndef _8_HASHTABLE_H
#define _8_HASHTABLE_H

typedef int (*HashFuncRaw)(const void *value);

class HashFunc {
public :
    virtual int operator()(const void *value) = 0;
    virtual ~HashFunc() {}
};

class HashTable {
public :
    HashTable(HashFunc &hc) : __hc(&hc), __hcr(nullptr) {}
    HashTable(HashFuncRaw hc) : __hcr(hc), __hc(nullptr) {}
    int get_hash(const void *data) {
        if (this->__hc) {
            return (*(this->__hc))(data);
        }else {
            return this->__hcr(data);
        }
    }    

private :
    HashFunc *__hc;
    HashFuncRaw __hcr;
};

#endif
