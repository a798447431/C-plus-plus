/*************************************************************************
	> File Name: 12.visitor_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 19时47分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct B;
struct C;
struct D;
struct E;


struct A {
    struct IVisitor {
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
    };
    virtual void Accept(IVisitor *) = 0;
    virtual ~A() {}
};

struct B : A {
    B() {
        x = 12567;
    }
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    int x;
};

struct C : A {
    C() {
        x = 90.87;
    }
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    double x;
};

struct D : A {
    D() {
        str = "hello world";
    }
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    string str;
};

struct E : A {
    E() {
        x;
    }
    virtual void Accept(IVisitor *vis) {
        vis->visit(this);
    }
    int *x;
};

struct OutputVisitor : A::IVisitor {
    virtual void visit(B *obj) {
        cout << "Class B" << endl;
    }
    virtual void visit(C *obj) {
        cout << "Class C" << endl;
    }
    virtual void visit(D *obj) {
        cout << "Class D" << endl;
    }
    virtual void visit(E *obj) {
        cout << "Class E" << endl;
    } 
};

struct CalVisitor : A::IVisitor {
    CalVisitor(int val) : val(val) {}
    virtual void visit(B *obj) {
        val += 2;
    }
    virtual void visit(C *obj) {
        val *= 3;
    }
    virtual void visit(D *obj) {
        val -= 5;
    }
    virtual void visit(E *obj) {
        val += 6;
    }
    int val;
};

ostream &operator<<(ostream &out, const CalVisitor &vis) {
    out << vis.val;
    return out;
}

int main() {
    srand(time(0));
    A *pa_arr[10];
    for (int i = 0; i < 10; i++) {
        switch (rand() % 4) {
            case 0: pa_arr[i] = new B(); break;
            case 1: pa_arr[i] = new C(); break;
            case 2: pa_arr[i] = new D(); break;
            case 3: pa_arr[i] = new E(); break;
        }
    }
    OutputVisitor vis;
    CalVisitor cvis(1);
    for (int i = 0; i < 10; i++) {
        pa_arr[i]->Accept(&vis);
        pa_arr[i]->Accept(&cvis);
    }
    cout << cvis << endl;
    return 0;
}
