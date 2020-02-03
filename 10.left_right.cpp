/*************************************************************************
	> File Name: 10.left_right.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月05日 星期四 13时48分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define P(func, x) { \
    cout << #func << "(" << #x << ") "; \
    func(x); \
}
void Judge2(int &x) {
    cout << "left value" << endl;
    return ;
}

void Judge2(int &&x) {
    cout << "right value" << endl;
    return ;
}

void Judge(int &x) {
    cout << "left value" << endl;
    //P(Judge2, std::forward<int &&>(x));
    //P(Judge2, std::move(x)); //右值与移动构造有关联
    P(Judge2, forward<int &>(x));
    return ;
}

void Judge(int &&x) { //该函数中一直可以访问到x 是左值，也是右值引用
    cout << "right value" << endl;
    P(Judge2, forward<int &&>(x));
    return ;
}

int main() {
    int a = 1, b = 2;
    P(Judge, a);
    P(Judge, b);
    P(Judge, 123);
    P(Judge, a + b);
    P(Judge, a++);//a自增之前的值，下一行就访问不到了，右值
    P(Judge, ++a);//a自增后的值，下一行依旧为这个值可以被访问，左值
    return 0;
}
