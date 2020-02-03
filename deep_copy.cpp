/*************************************************************************
	> File Name: deep_copy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月13日 星期日 11时50分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {
        str = new char[100];
    }
    ~A() {
        delete[] str;
    }
private:
    char *str;
};

int main() {
    A a, b = a;
    cout << "hello haizei" << endl;
    return 0;

}
