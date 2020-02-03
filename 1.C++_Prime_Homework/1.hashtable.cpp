/*************************************************************************
	> File Name: 1.hashtable.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月26日 星期六 16时55分50秒
 ************************************************************************/

#include <iostream>
#include "1.hashtable.h"
using namespace std;

class MyHash : public HashFunc {
public :
    int operator()(const void *value) {
        const char *str = (const char *)(value);
        int hash_code = 0, seed = 131;
        while (*str) {
            hash_code = hash_code * seed + str[0];
            str++;
        }
        return hash_code & 0x7fffffff;
    }
};

int main() {
    MyHash func;
    char str[1024] = {0};
    int op, num;
    cin >> num;
    HashTable h(func, num);
    while (cin >> op) {
        cin >> str;
        switch(op) {
            case 0: {
                cout << "下标：" << h.insert(str, num) << endl;
            } break;
            case 1: {
                if (h.find(str, num)) cout << "查找成功!" << endl;
                else cout << "查找失败!" << endl;
            } break;
        }
    }
    return 0;
}
