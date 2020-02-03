/*************************************************************************
	> File Name: 1.array.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年09月02日 星期一 10时33分27秒
 ************************************************************************/
//有大量BUG!

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
//保留struct,迁就C语言,与C语言中的struct实现方式完全不同
class Array {
public :
    Array() {
        this->__size = 10;
        this->__cnt = 0;
        this->data = new T[this->__size];
    }
    Array(int n) {
        this->__size = 2 * n;
        this->__cnt = n;
        this->data = new T[this->__size];
    }
    void push_back(const T &a) {
        this->data[(this->__cnt)++] = a; //有BUG,源自复制方式
    }
    int size() {
        return this->__cnt;
    }
    T &operator[](int ind) {
        return this->data[ind];
    }

private:
    T *data;
    int __size, __cnt;
};


int main() {
    vector<int> arr(10);
    Array<int> arr2(10);

    cout << arr.size() << endl;
    arr.push_back(123);
    cout << arr[0] << endl;
    cout << arr.size() << endl;
    
    cout << arr2.size() << endl;
    arr2.push_back(123);
    cout << arr2[0] << endl;
    cout << arr2.size() << endl;

    return 0;
}
