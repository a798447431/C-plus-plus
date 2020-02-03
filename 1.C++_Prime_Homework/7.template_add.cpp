/*************************************************************************
	> File Name: 7.template_add.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 15时27分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A(int x) : x(x) {}
    int operator+(const int y) {
        return this->x + y;
    }
    int operator+(const A &a) {
        return this->x + a.x;
    }
private:
    int x;
};

template<typename T, typename U>
auto add(T &a, U &b) -> decltype(a + b) {
    return a + b;
}

template<typename T>
struct Print {
    template<typename U>
    void operator()(U &&a) {
        cout << a << endl;
    }
};

template<typename T>
void func(T a) {
    cout << a << endl;
}

template<typename T, typename ...REST>
struct ARG {
    typedef T __type;
    typedef ARG<REST...> __rest;
};

template<typename T>
struct ARG<T> {
    typedef T __type;
};

template<typename T, typename ...ARGS> struct Test;
template<typename T, typename ...ARGS>
struct Test<T(ARGS...)> {
    T operator()(
        typename ARG<ARGS...>::__type a, 
        typename ARG<ARGS...>::__rest::__type b) {
        return a + b;
    }
};

int main() {
    int a = 3, b = 4;
    double c = 4.5;
    A d(2);
    func(a);
    func(c);
    Print<int> plog;
    plog(a);
    plog(c);
    plog(add(a, b));
    cout << add(a, c) << endl;
    cout << add(c, a) << endl;
    cout << add(d, a) << endl;
    Test<int(int, double)> func_a;
    Test<double(int, int)> func_b;
    cout << func_b(12, 23) << endl;    
    return 0;
}
