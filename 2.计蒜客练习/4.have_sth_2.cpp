#include <iostream>
#include <string>
#include <memory>

using namespace std;

class A {
public:
    string name;
    A(const string& theName) : name{ theName }
    {

    }
};

int main() {
    auto x = make_shared<A>("A");
    cout << x->name << endl;
    {
        auto y = x;
        cout << y->name << endl;
    }
    weak_ptr<A> w = x;
    {
        auto y = w.lock();
        cout << x->name << endl;
    }

    x = nullptr;
    {
        auto y = w.lock();
        if (y) {
            cout << "w不为空" << endl;
        } else {
            cout << "w为空" << endl;
        }
    }
    return 0;
}

