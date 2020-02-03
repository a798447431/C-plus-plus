/*************************************************************************
	> File Name: 9.template.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月05日 星期四 08时11分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public :
    A(int x) : x(x) {}
    int operator+(const int y) {
        return this->x + y;
    }
    int operator+(const A &a) {
        return this->x + a.x;
    }
private :
    int x;
};

template<typename T, typename U> 
//decltype((*((T *)0)) + (*((U *)0))) add(T &a, U &b) {
auto add(T &a, U &b) -> decltype(a + b){
    return a + b;
}

//typename 与 class没有任何区别
template<typename T>
struct Print {
    // T &a 左值引用 一直存在的值称为左值
    // 当在程序中定义了模板方法但没有去用它的时候，它在程序编译完之后是一点空间都不占的
    template<typename U>
    void operator()(U &&a) {
        cout << a << endl;
    }
};

template<typename T>
void func(T a) {
    cout << a << endl;
}

//第一次调用func是 进行实例化
//第一次实例化
//void func(int a) {
//cout << a << endl;
//}
//第二次实例化
//void func(double a) {
//cout << a << endl;
//}
//根据func使用情况，把模板中的参数类型替换掉
//真正编译的时候，是拿着实例化的函数方法去编译

template<typename T>
void print(const T &a) {
    cout << a << endl;
    cout << "end----" << endl;
    return ;
}

template<typename T, typename ...ARGS> 
void print(const T &a, ARGS... args) {
    cout << a << endl;
    print(args...);
    return ;
}

template<int n, typename T, typename ...U>
struct ARG {
    typedef T type;
    typedef typename ARG<n-1, U...>::getT getT;
};

template<typename T, typename ...U>
struct ARG<1, T, U...> {
    typedef T type;
    typedef T getT;
};

template<typename T, typename ...U> struct Convertor;
template<typename T, typename ...U> 
struct Convertor<T(U...)> {
    T operator()(
        const typename ARG<1, U...>::getT &a,
        const typename ARG<2, U...>::getT &b) {
        return a + b;
    }
};

template<int n, int m>
void func() {
    cout << "func : " << n + m << endl;
    return ;
}

template<int n>
struct IsOdd {
    const static int r = n % 2;
};

template<int n, int i>
struct GetNextN {
    const static int r = (n > 0 && n % i != 0) * n;
};

template<int n, int i>
struct GetNextM {
    const static int r = (i * i <= n ? i + 1 : 0);
};

template<int n, int i>
struct TestPrime {
    const static int r = TestPrime<GetNextN<n, i>::r, GetNextM<n, i>::r>::r; //to do
    
};

template<int i>
struct TestPrime<0, i> {
    const static int r = 0;
};

template<int n>
struct TestPrime<n, 0> {
    const static int r = 1;
};

template<int n>
struct IsPrime {
    const static int r = TestPrime<n, 2>::r;
};

/*
for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false; 
}
return true;
*/

int main() {
    int a = 3, b = 4;
    double c = 4.5;
    /*
        func(a);
        func(c);
    */

    //decltype在编译期执行，不去计算表达式的值，只会计算表达式的返回值类型
    A d(2);
    Print<int> plog;
    //a + b =7 过了44行就访问不到了，这种临时值可以看作右值
    plog(a);
    plog(c);
    func<2, 3>();
    func<3, 4>();
    func<7, 9>();
    func<3, 9>();
    plog(add(a, b));
    cout << add(a, c) << endl;
    cout << add(c, a) << endl;
    cout << d + a << endl;
    cout << add(d, a) << endl;
    print(1, 2.3, "hello world");
    Convertor<int(double, double)> conv;
    cout << conv(3.4, 4.5) << endl;

    cout << IsOdd<2>::r << endl;
    cout << IsOdd<3>::r << endl;
    
    cout << IsPrime<9>::r << endl;
    cout << IsPrime<1007>::r << endl;
    
    return 0;
}
