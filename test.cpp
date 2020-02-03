/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月26日 星期六 14时52分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Animal {
public :
    Animal(const string &name) : __name(name){}
    virtual void run() {
        cout << "I don't know how can run" << endl;
    }
protected:
    string __name;
};

class Cat : public Animal {
public :
    Cat() : Animal("cat") {}
    void run() override {
        cout << "I can run with four legs" << endl;
    }
};

int main() {
    Cat a;
    Animal &b = a;
    Animal *c = &a;
    a.run();
    b.run();
    c->run();
    return 0;
}
