/*************************************************************************
	> File Name: 2.object.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月16日 星期三 10时04分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct X {
    X() = delete;
    X(const X&) = delete;
    X(int) {  } 
};

struct Y {
    X x;
    Y() = delete;
    Y(const Y&) = delete;
    Y(int) : x{0} {}
};

int main() {
    Y y1{0};
    Y y2 = y1;
   // Y y2 = y1;
    return 0;
}
