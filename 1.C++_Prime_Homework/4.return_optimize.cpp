/*************************************************************************
	> File Name: 4.return_optimize.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月12日 星期六 19时16分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

Class A {
public:
    A() {
        cout << "constructor" << endl;
    }
    A(const string &a) {
        cout << "constructor with parameters" << endl;
    }
    A(const A &obj) {
        
    } 
    ~A() {}
private:
    string str;
}

int main() {

    return 0;
}
