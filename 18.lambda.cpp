/*************************************************************************
	> File Name: 18.lambda.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 20时10分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

auto add = [](int a, int b) -> long long {
    return a + b;
};

auto Data = [](int a, int b) {
    return [=](auto func) {
        return func(a, b);
    };
};

auto First = [](int a, int b) {
    return a;
};

auto Second = [](int a, int b) {
    return b;
};

auto Add = [](int a, int b) {
    return a + b;
};

auto Max = [](int a, int b) {
    return max(a, b);  
};

int main() { 
    cout << add(2, 4) << endl;
    auto a = Data(2, 4);
    cout << a(First) << endl;
    cout << a(Second) << endl;
    cout << a(Add) << endl;
    cout << a(Max) << endl;
    return 0;
}
