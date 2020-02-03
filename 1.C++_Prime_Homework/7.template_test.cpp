/*************************************************************************
	> File Name: 7.template_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月07日 星期四 19时52分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

template<int n, typename T, typename ...ARGS>
struct ARG {
    //typedef T __type;
    typedef typename ARG<n - 1, ARGS...>::getT getT;
};

template<typename T, typename ...ARGS>
struct ARG<1, T, ARGS...> {
    typedef T getT;
};

template<typename T, typename ...ARGS> struct Test;
template<typename T, typename ...ARGS>
struct Test<T(ARGS...)> {
    T operator()(
        typename ARG<1, ARGS...>::getT a,
        typename ARG<2, ARGS...>::getT b
    ) {
        return a + b;
    }
};

struct ClassA {
    ClassA(int x) : x(x) {}
    int operator+(int x) {
        return this->x + x;
    }
    int x;

private:
    ClassA(const ClassA &A) {}
};

template<typename T, typename U> 

auto add(T &&a, U &&b) -> decltype(a + b) { //模板中&&不叫右值引用 引用折叠
    return a + b;
}

template<int n>
struct IsOdd {
    const static int r = n % 2;
};

template<int n, int i>
struct getNextN {
    const static int r = (n % i ? n : 0)
};

template<int n, int i> 
struct isTest {
    const static int r = isTest<getNextN<n, i>::r, getNextI<n, i>::r>;
};

template<int n> 
struct IsPrime {
    const static int r = 
};

int main() {
    int a = 1, b = 2;
    cout << add(a, b) << endl;
    cout << add(a, 4.5) << endl;
    ClassA c(12);
    cout << add(c, 6) << endl;
    cout << IsOdd<2>::r << endl;
    cout << IsOdd<3>::r << endl;
    cout << IsPrime<9>::r << endl;
    cout << IsPrime<9973>::r << endl;
    return 0;
}
