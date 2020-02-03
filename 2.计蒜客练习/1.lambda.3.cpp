/*************************************************************************
	> File Name: 1.lambda.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月07日 星期一 15时21分45秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int Count(vector<int>& numbers, bool(*filter)(int, void*), void* context) {
    int counter = 0;
    for (int x : numbers) {
        if (filter(x, context)) {
            counter++;
        }
    }
    return counter;
}

bool GreaterThan(int x, void* context) {
    return x > *reinterpret_cast<int*>(context);
}

int CountGreaterThan(vector<int>& numbers, int y) {
    return Count(numbers, &GreaterThan, &y);
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
