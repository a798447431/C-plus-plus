#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
/*
int main() {
    vector<int> numbers = {7, 1, 12, 2, 8, 3, 11, 4, 9, 5, 13, 6, 10};
    sort(begin(numbers), end(numbers), [](int a, int b)
    {
       return a < b;  
    });
    return 0;
}
*/

function<bool(int)> Predicator(vector<int>&& ys) {
    return [ys = move(ys)](int x)
    {
        return find(begin(ys), end(ys), x) != end(ys);
    };
}

int main() {
    vector<int> xs = { 1, 2, 3, 4, 5 };
    vector<int> ys = { 3, 4, 5, 6, 7 };
    auto count = count_if(begin(xs), end(xs), Predicator({3, 4, 5, 6, 7}));
    cout << count << endl;
    return 0;
}
