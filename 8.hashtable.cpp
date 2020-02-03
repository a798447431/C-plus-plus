/*************************************************************************
	> File Name: 8.hashtable.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 14时14分56秒
 ************************************************************************/

#include <iostream>
#include "8.hashtable.h"
using std::cin;
using std::cout;
using std::endl;

class MyHash1 : public HashFunc {
public :
    int operator()(const void *value) {
        const char *str = (const char *)(value);
        int hash_code = 0, seed = 131;
        while (*str) {
            hash_code += hash_code * seed + str[0];
            str++;
        }
        return hash_code & 0x7fffffff;
    }
};

int MyHash2(const void *data) {
    const char *str = (const char *)(data);
    int hash_code = 0, i = 0;
    while (*str) {
        if (i & 1) {
            hash_code = (hash_code << 7) ^ str[0] ^ (hash_code >> 3);
        } else {
            hash_code = (~((hash_code << 11) ^ str[0] ^ (hash_code >> 5)));
        }
        str++;
    }
    return hash_code & 0x7fffffff;
}

int main() {
    MyHash1 func1;
    HashTable h1(func1), h2(MyHash2);
    cout << h1.get_hash("hello world") << endl;
    cout << h1.get_hash("hello haizei") << endl;
    cout << h2.get_hash("hello world") << endl;
    cout << h2.get_hash("hello haizei") << endl;
    return 0;
}
