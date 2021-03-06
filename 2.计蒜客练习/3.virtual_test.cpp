#include <iostream>

using namespace std;

class Animal{
public:
    string name;
    virtual ~Animal(){}
    virtual string Introduce() {
        return "我不知道自己是什么动物。";
    }
};

class Cat : public Animal {
public:
    string Introduce() override {
        return "我是一只猫, 我的名字是\"" + name + "\"。";
    }
};

class Dog : public Animal {
public:
    string Introduce() override {
        return "我是一只狗, 我的名字是\"" + name + "\"。";
    }
};

void IntroduceAnAnimal(Animal &animal) {
    cout << animal.Introduce() << endl;
}

int main() {
    Cat cat;
    cat.name = "Tom";

    Dog dog;
    dog.name = "Spike";
    
    Animal animal;
    animal.name = "nothing";
    
    IntroduceAnAnimal(cat);
    IntroduceAnAnimal(dog);
    IntroduceAnAnimal(animal);
    
    return 0;
}

