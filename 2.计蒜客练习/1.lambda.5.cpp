/*************************************************************************
	> File Name: 1.lambda.5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月07日 星期一 15时46分33秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int a = 0;

int main() {
    auto inc = [&a](){ a++; };
    inc();
    inc();
    cout << a << endl;
    return 0;
}
