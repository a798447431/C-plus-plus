/*************************************************************************
	> File Name: 2.right_value_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月16日 星期三 13时41分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

void Print(int& x) {
    cout << "x is int&" << endl;
}

void Print(int&& x) {
    cout << "x is int&&" << endl;
}

template<typename T>
void CallPrint(T&& x) {
    Print(x);
}

int main() {
    int x = 0;
    CallPrint(x);
    CallPrint(0);
    return 0;
}
