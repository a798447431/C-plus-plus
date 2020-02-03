/*************************************************************************
	> File Name: 2.struct_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月13日 星期日 14时25分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    int a;
};

struct B : A {

};

int main() {
    B b;
    b.a = 0;
    cout << b.a << endl;
    return 0;
}
