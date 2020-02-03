/*************************************************************************
	> File Name: 4.succeed.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月03日 星期二 13时17分19秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public :
    Data() {}
    Data(const string &data) {
        cout << data << endl;
    }
};

class Animal {
public :
    Animal(const string &name, int x = 0) : d2("I'm d2"), d1("I'm d1"), _name(name), _x(x) {
        cout << "Animal Constructor" << endl;
    }
    string name() { return this->_name; }
    Animal(const Animal &a) : _x(a._x + 1), _name(a._name) {}
    int x() { return this->_x; }
    void run() {
        cout << "I can run" << endl;
    }
    ~Animal() {
        cout << "Animal Destructor" << endl;
    }

private :
    Data d1, d2;
    string _name;
    int _x;
};

//X是一个XXX东西
class Cat : public Animal {
public :
    Cat() : Animal("cat-1") {
        cout << "Cat Constructor" << endl;
    }
    Cat(const Cat &obj) : Animal(obj), _y(obj._y) {}
    void run() {
        cout << "I can run, like a Cat" << endl;
    } 
    Cat(string name, int x, int y) : Animal(name, x), _y(y) {}
    int y() { return this->_y; }
    ~Cat() {
        cout << "Cat Destructor" << endl;
    }

private :
    int _y;
};

class Dog : public Animal {
public :
    Dog() : Animal("Dog-1") {}
    void run() {
        cout << "I can run, like a dog" << endl;
    }
};

ostream &operator<<(ostream &out, Cat &a) {
    out << "<Class Cat> ";
    out << a.name() << " " << a.x() << " " << a.y();
    return out;
}

int main() {
    Cat c1("hello kitty", 0, 54);
    Cat c2(c1);
    Dog d1;
    cout << c1 << endl;
    cout << c2 << endl;
    Animal a1("Other");
    Animal *p[2] = {&c1, &d1};
    p[0]->run();
    p[1]->run();
    return 0;
}

