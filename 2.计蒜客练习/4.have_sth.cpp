#include<iostream>
#include<string>
#include<memory>

using namespace std;

class A {
public:
    string name;
    A(const string& theName) : name{ theName }
    {

    }
};

int main() {
    auto x = make_unique<A>("A");
    cout << x->name << endl;
    unique_ptr<A> y(x.release());
    if (x) {
        cout << "x不为空" << endl;
    }
    else {
        cout << "x为空" << endl;
    }
    cout << y->name << endl;
    return 0;
}

