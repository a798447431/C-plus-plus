/*************************************************************************
	> File Name: 6.virtual_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月26日 星期六 15时38分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Animal {
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
};

struct Cat : Animal {
    void run() override{
        cout << "I can run like a cat" << endl;
    }
};

struct Dog : Animal {
    void run() override {
        cout << "I can run like a dog" << endl;
    }
};

struct Bat : Animal {
    int age;
};

int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) {
            arr[i] = new Cat;
        } else {
            arr[i] = new Dog;
        }
    }
    arr[8]->run();
    cout << sizeof(Bat) << endl;
    return 0;
}
