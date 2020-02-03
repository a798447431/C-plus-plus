/*************************************************************************
	> File Name: 6.virtual.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 10时54分22秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    Animal() {}
    Animal(string name) : _name(name), _age(3) {}
    virtual void run() {
        cout << _name << " : I don't know how to run" << endl;
    }
    string name() { return this->_name; }
    int &age() { return this->_age; }
    virtual ~Animal() {
        cout << "Animal Destructor" << endl;
    }

private :
    string _name;
    int _age;
};

class Cat : public Animal {
public :
    Cat() : Animal("Cat-1") {}
    void run() {
        cout << name() << " : I can run with four legs" << endl;
    }
    ~Cat() {
        cout << "Cat Destructor" << endl;
    }
};

class Dog : virtual public Animal {
public :
    Dog() : Animal("Dog-1") {}
    void run() {
        cout << name() << " : I can wang wang run" << endl;
    }
    int seek_age() { 
        cout << "Dog seek age : " << &age() << endl;
        return age(); 
    }
    ~Dog() {
        cout << "Dog Destructor" << endl;
    }
};

class Bat : virtual public Animal {
public :
    Bat() : Animal("Bat-1") {}
    void run() {
        cout << name() << " : I can flying" << endl;
    }
    void change_age() {
        age() += 1;
        cout << "Bat chang age : " << age() << " " << &age() << endl;
    }
    ~Bat() {
        cout << "Bat Destructor" << endl;
    }
};

class SkyDog : public Dog, public Bat {
public :
    void run() {
        cout << "SkyDog : I can suibian run" << endl;
    }
};

Animal *getAnimal() {
    int val = rand() % 3;
    switch (val) {
        case 0: return new Cat();
        case 1: return new Dog();
        case 2: return new Bat();
    }
    return nullptr; //特殊空指针 不是0 就是空
}

void func(Animal *p) {
    cout << "func p = " << p << endl;
}

void func(int x) {
    cout << "func x(int) = " << x << endl;
}

int main() {
    srand(time(0));
    func(nullptr);
    Animal **arr = new Animal*[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = getAnimal();
    }
    for (int i = 0; i < 20; i++) {
        arr[i]->run();
    }
    for (int i = 0; i < 20; i++) {
        delete arr[i];   
    }
    SkyDog sd;
    sd.change_age();
    sd.change_age();
    sd.change_age();
    sd.change_age();
    sd.change_age();
    sd.change_age();
    cout << sd.seek_age() << endl;
    return 0;
}
