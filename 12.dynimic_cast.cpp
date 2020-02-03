/*************************************************************************
	> File Name: 12.visitor_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 19时08分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct A {
    virtual ~A() {}
};

struct B : A {
    B() {
        x = 12567;
    }
    void say() {
        cout << "Class B : " << x << endl;
    }
    int x;
};

struct C : A {
    C() {
        x = 90.87;
    }
    void say() {
        cout << "Class C : " << x << endl;
    }
    double x;
};

struct D : A {
    D() {
        str = "hello world";
    }
    void say() {
        cout << "Class D : " << str << endl;
    }
    string str;
};

struct E : A {
    E() {
        x;
    }
    void say() {
        cout << "Class E : " << x << endl;
    }
    int *x;
};

int main() {
    srand(time(0));
    A *pa = nullptr;
    /*
    B *pb = dynamic_cast<B *>(pa);
    C *pc = dynamic_cast<C *>(pa);
    cout << pb << endl;
    cout << pc << endl;
    */
    switch(rand() % 4) {
        case 0: pa = new B(); break; 
        case 1: pa = new C(); break;
        case 2: pa = new D(); break;
        case 3: pa = new E(); break;
    }
    if (dynamic_cast<B *>(pa)) {
        ((B *)(pa))->say();
    } else if (dynamic_cast<C *>(pa)) {
        ((C *)(pa))->say();
    } else if (dynamic_cast<D *>(pa)) {
        ((D *)(pa))->say();
    } else if (dynamic_cast<E *>(pa)) {
        ((E *)(pa))->say();
    }
    return 0;
}
