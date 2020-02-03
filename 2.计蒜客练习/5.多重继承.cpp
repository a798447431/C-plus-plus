#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct A {
    virtual ~A() = default;
    virtual void PrintA() {
        cout << "A::PrintA" << endl;
    }
};

struct B {
    virtual ~B() = default;
    virtual void PrintB() {
        cout << "B::PrintB" << endl;
    }
};  

struct C : A, B {
    void PrintA() override {
        cout << "C::PrintA" << endl;
    }
    void PrintB() override {
        cout << "C::PrintB" << endl;
    }
};

int main() {
    C c;
    A *pa = &c;
    B *pb = &c;
    pa->PrintA();
    pa->A::PrintA();
    pb->PrintB();
    pb->B::PrintB();
    return 0;
}

