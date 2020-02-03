/*************************************************************************
	> File Name: 7.virtual_table.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 13时22分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    virtual void run(int x) {
        cout << "class A run" << endl;
    }
};

class B : public A {
public :
    void run(int x) {
        cout << "class B run" << endl;
        cout << this << endl;
        cout << x << endl;
    }
};

typedef void (*func)(void *, int);

int main() {
    B b;
    ((func **)(&b))[0][0](&b, 123);
    return 0;
}
