/*************************************************************************
	> File Name: 1.lambda.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月07日 星期一 14时20分54秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int Count(vector<int>& numbers, bool(*filter)(int)) {
    int counter = 0;
    for (int x : numbers) {
        if (filter(x)) {
            counter++;
        }
    }
    return counter;
}

bool Odd(int x) {
    return x % 2 == 1;
}

bool Event(int x) {
    return x % 2 == 0;
}

int CountOdds(vector<int>& numbers) {
    return Count(numbers, &Odd);
}

int CountEvens(vector<int>& numbers) {
    return Count(numbers, &Event);
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
