#include <iostream>

using namespace std;

struct Base {

};

struct Derived : Base {
    string s {"This is a very long string that force std::string to allocate a buffer."};
};

int main() {
    Base *obj = new Derived;
    delete obj;
    return 0;
}

