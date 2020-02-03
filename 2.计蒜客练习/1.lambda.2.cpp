/*************************************************************************
	> File Name: 1.lambda.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月07日 星期一 14时41分58秒
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

int CountOdds(vector<int>& numbers) {
    return Count(numbers, [](int x){ return x % 2 == 1; });
}

int CountEvens(vector<int>& numbers) {
    return Count(numbers, [](int x){ return x % 2 == 0; });
}

vector<int> obj;

int main() {
    for (int i = 0; i < 10; i++) {
        obj.push_back(i);
    }
    cout << CountOdds(obj) << endl;
    cout << CountEvens(obj) << endl;
    return 0;
}
