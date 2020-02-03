#include <iostream>
using namespace std;

class A{
public:
    A() {
        cout << "A's constructor" << endl;
    }
    ~A() {
        cout << "A's destructor" << endl;
    }
    void show() {
        cout << "num:" << num << endl;
    }
private:
    int num;
};

class B{
public:
    B() {
        cout << "B's constructor" << endl;
    }
    ~B() {
        cout << "B's destructor" << endl;
    }
    void SetNum(int n) {
        num = n;
    }
    int GetNum() {
        return num;
    }
private:
    int num;
};

int main() {
    /*
    char mem[100];
    mem[0] = 'A';
    mem[1] = '\0';
    mem[2] = '\0';
    mem[3] = '\0';
    cout << (void*)mem << endl;
    A *p = new (mem)A;
    cout << p << endl;
    p->show();
    p->~A();
    getchar();
    */
    char *mem = new char[10 * sizeof(B)];
    cout << (void*)mem << endl;
    B *p = new(mem)B;
    cout << p << endl;
    p->SetNum(10);
    cout << p->GetNum() << endl;
    p->~B();
    delete[] mem;
    getchar();
    return 0;
}

