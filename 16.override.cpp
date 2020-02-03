/*************************************************************************
	> File Name: 16.override.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 15时48分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct A {
    virtual void func1() final = 0; //final关键字保证函数不被覆盖
    void funcl() {
        cout << "Class A func ai ou" << endl;
    }
};

struct B : A { //final类被继承时直接报错
    void func1() override {
        cout << "Class B func ai ou" << endl;
    }
};

int main() {
    B b;
    A *a = &b;
    a->funcl();
    return 0;
}
