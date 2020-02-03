/*************************************************************************
	> File Name: left_right_value.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 15时17分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define P(a) { \
    printf("judge : %s\n", #a); \
    func(a); \
}

void judge(int &a) {
    cout << "judge = left value : " << a << endl;
    return ;
}

void judge(int &&a) {
    cout << "judge = right value : " << a << endl;
    return ;
}

int func(int &a) {
    cout << "left value : " << a << endl;
    judge(a);
    return 0;
}

int func(int &&a) {
    cout << "right value : " << a << endl;
    //judge(forward<int &&>(a));
    judge(move(a));
    return 0;
}

int main() {
    int a = 1, b = 12, c = 13;
    P(a);
    P(b + c);
    P(12 + 15);
    P(1);
    P(++a);
    P(a++);
    return 0;
}
