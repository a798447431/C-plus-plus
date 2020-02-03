/*************************************************************************
	> File Name: 6.succeed.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月13日 星期日 18时23分47秒
 ************************************************************************/
#include<iostream>
using namespace std;
#define P_ADD(x) cout << #x << " " << &(x) << endl

class Animal {
public :
    //Animal() {}
    Animal(const char *name) : _name(name) {
        cout << "Animal " << this << endl;
    }
    const char *name() const { return this->_name; }
    void say() {
        cout << "I'm an Animal" << endl;
    }
    int x, y;
private :
    const char *_name;
};

class Cat : public Animal {
public :
    Cat() : Animal("hello kitty") {
        cout << "Cat " << this << endl;
    }
    void say() {
        cout << "I'm a Cat" << endl;
    }
    int z;
};

class Dog : public Animal {
public :
    Dog() : Animal("Anby") {
        cout << "Dog " << this << endl;
    }
    void say (){
        cout << "I'm a Dog" << endl;
    }
};

class Monkey : public Animal {
public :
    Monkey() : Animal("Monkey six") {
        cout << "Monkey " << this << endl;
    }
};

ostream &operator<<(ostream &out, const Cat &a) {
    out << "<class Cat (" << sizeof(a) << ")> : ";
    out << a.name() << endl;
    P_ADD(a.x);
    P_ADD(a.y);
    P_ADD(a.z);
    return out;
}
ostream &operator<<(ostream &out, const Dog &b) {
    out << "<class Dog> : ";
    out << b.name();
    return out;
}
ostream &operator<<(ostream &out, const Monkey &c) {
    out << "<class Monkey> : ";
    out << c.name();
    return out;
}

int main() {
    Cat a;
    Dog b;
    Monkey c;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    Animal *p[2] = {&a, &b};
    a.say();
    p[0]->say();
    p[1]->say();
    return 0;
}
