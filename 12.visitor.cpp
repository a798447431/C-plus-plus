/*************************************************************************
	> File Name: 12.visitor.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月05日 星期四 15时56分13秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Cat;
struct Dog;
struct People;

struct Animal {
    struct IVisitor {
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(People *) = 0;
    };
    Animal(string name) : name(name) {}
    virtual void say() = 0;
    virtual void Accept(IVisitor *) = 0;
    string name;
    int age;
    virtual ~Animal() {}
};

struct Cat : Animal {
    Cat() : Animal("Cat") {
        this->age = rand() % 100;
    }
    void say() {
        cout << "miao miao maio" << endl;
    }
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

struct Dog : Animal {
    Dog() : Animal("Dog") {
        this->age = rand() % 50;
    }
    void say() {
        cout << "wang wang wang" << endl;
    }
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

struct People : Animal {
    People() : Animal("People") {
        this->age = rand() % 200;
    }
    void say() {
        cout << "ai ya ma ya" << endl;
    }
    void Accept(IVisitor *vis) {
        vis->visit(this);
    }
};

Animal *genCat() {
    return new Cat;
}

Animal *genDog() {
    return new Dog;
}

Animal *genPeople() {
    return new People;
}

struct OutputVisitor : Animal::IVisitor {
    void visit(Cat *a) {
        cout << "this is a cat " << a->age << endl;
    }
    void visit(Dog *a) {
        cout << "this is a dog " << a->age << endl;
    }
    void visit(People *a) {
        cout << "this is a person " << a->age << endl;
    }
};

struct AgeVisitor : Animal::IVisitor {
    void visit(Cat *a) {
        this->age = a->age - 3; 
    }
    void visit(Dog *a) {
        this->age = a->age + 3; 
    }
    void visit(People *a) {
        this->age = a->age * 2; 
    }
    int age;
};

int main() {
    srand(time(0));
    Animal *arr[10];
    Animal *(*func_arr[3])() = {
        genCat, genDog, genPeople
    };
    for (int i = 0; i < 10; i++) {
        int x = rand() % 3;
        arr[i] = func_arr[x]();
    }
    for (int i = 0; i < 10; i++) {
        OutputVisitor ov;
        AgeVisitor av;
        arr[i]->Accept(&ov);
        arr[i]->Accept(&av);
        cout << av.age << endl;
    }
    return 0;
}

