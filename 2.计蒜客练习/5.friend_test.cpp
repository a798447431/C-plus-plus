#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct B;
extern void F(B* b);

struct B {
    struct A
    {
        friend void F(B *b);
    };
private:
    int data;
};

void F(B *b) {
    cout << b->data << endl;
}

int main() {
    B b;
    F(&b);
    return 0;
}

