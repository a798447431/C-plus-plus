#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> xs{ 1, 2, 3, 4, 5 };
    transform(begin(xs), end(xs), begin(xs), [](int x){return x * 2;});
    return 0;
}

