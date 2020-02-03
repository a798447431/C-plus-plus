#include <iostream>

using namespace std;

class A {
public:
    virtual ~A() = default;
    virtual void F() = 0;
};

class B : public A {
public:
    void F() = 0;
};

int main() {
    B b;
    return 0;
}

