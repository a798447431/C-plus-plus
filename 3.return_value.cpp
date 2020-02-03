/*************************************************************************
	> File Name: 3.return_value.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年09月02日 星期一 16时19分33秒
 ************************************************************************/

#include <iostream>

using namespace std;

class A {
public :
    A() {
        cout << this << " constructor" << endl;
    }
    A(const A &obj) {
        cout << this << " copy constructor" << endl;
    }
    A &operator=(const A &obj) {
        cout << this << " operator = " << endl;
        return *this;
    }
    ~A() {
        cout << this << " destructor" << endl;
    }
};

A func() {
    A temp;
    cout << &temp << endl;
    return temp; //temp_a 作为 a的别名
}

int main() {
    /*
    A a = func(); //拷贝构造函数
    cout << &a << endl;
    */
    A a;
    a = func(); //赋值运算符
    return 0;
}
