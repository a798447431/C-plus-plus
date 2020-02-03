/*************************************************************************
	> File Name: 14.nullptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 14时25分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

void func(int *p) {
    cout << "int * = " << p << endl;
}

void func(int x) {
    cout << "int = " << x << endl;
}

int main() {
    //func(NULL);
    func(nullptr); //nullptr 明确是一个空地址
    int *p1 = NULL, *p2 = nullptr;
    cout << p1 << endl;
    cout << p2 << endl;
    return 0;
}
