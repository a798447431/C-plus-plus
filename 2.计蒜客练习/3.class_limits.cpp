#include <iostream>

using namespace std;

template<typename T>
class X {
private:
    int member;

public:
    template<typename U>
    void Method(X<U>& y) {
        &y.member;
    }
};

class Base {
private:
    int a;
protected:
    int b;
};

class Derived : public Base {
public:
    void Method(Derived &y) {
        &y.a;
        &y.b;
    }
};

int main() {
    X<int> x;
    X<float> y;
    x.Method(x);
    x.Method<y>;
    return 0;
}

