/*************************************************************************
	> File Name: 1.lambda.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月07日 星期一 15时21分45秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

template<typename U>
int Count(vector<int>& numbers, U filter) {
    int counter = 0;
    for (int x : numbers) {
        if (filter(x)) {
            counter++;
        }
    }
    return counter;
}

int CountGreaterThan(vector<int>& numbers, int y) {
    return Count(numbers, [=](int x){ return x > y; });
}

vector<int> obj;

int main() {
    for (int i = 0; i < 10; i++) {
        obj.push_back(i);
    }
    cout << CountGreaterThan(obj, 5) << endl;
    cout << CountGreaterThan(obj, 8) << endl;
    return 0;
}
