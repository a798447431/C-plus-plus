/*************************************************************************
	> File Name: operator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月22日 星期二 20时52分50秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Data {
    Data(int x, int y) : x(x), y(y) {}
    int x, y;

};

Data operator+(Data &a, Data &b) {
    return Data(a.x + b.x, a.y + b.y);
}

int main() {
    Data a(2, 3), b(5, 6);
    Data c = a + b;
    return 0;
}
