/*************************************************************************
	> File Name: 15.constptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 14时47分29秒
 ************************************************************************/

#include<iostream>
using namespace std;

constexpr int add(int i) { //函数可以返回常量表达式，不是必须当作常量表达式用
    return i * 2;
}

struct ClassA {
    constexpr ClassA(int x, int y) : x(x), y(y){}
    int x, y;
};

int main() {
    constexpr int i = 1 + add(3);// 修饰变量时是必须的
    cout << i << endl;
    int n;
    cin >> n;
    cout << add(n) << endl;
    constexpr ClassA a(1, 2);
    return 0;
}
