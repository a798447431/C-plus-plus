/*************************************************************************
	> File Name: 2.function.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月07日 星期一 16时26分50秒
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

function<int(int)> Adder(int x) {
    return [=](int y){ return x + y; };
}

function<int(int)> Compose(function<int(int)> f, function<int(int)> g) {
    return [=](int y){ return f(g(y)); };
}

function<double(double)> inc = [](int x){ return 1 + x; };

int(*square)(int) = [](int x){ return x * x; };
 
int main() {
    auto adder = Compose(Adder(1), Adder(2));
    cout << adder(3) << endl;
    cout << inc(2.9) << endl;
    cout << square(3) << endl;
    return 0;
}
