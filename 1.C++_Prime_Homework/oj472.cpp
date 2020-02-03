/*************************************************************************
	> File Name: oj472.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月13日 星期日 20时26分39秒
 ************************************************************************/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class BigInt {
public:
    BigInt() {
        num.push_back(0);
    }
    int operator%(const int &a) {
        int result = 0;
        for (int i = 0; i < num.size(); i++) {
            result = (result * 10 + num[i]) % a;
        }
        return result;
    }
    void operator=(const string &str) {
        num.clear();
        for (int i = 0; i < str.size(); i++) {
            num.push_back(str[i] - '0');
        }
        return ;    
    }
    vector<int> num;
};

int main() {
    string str;
    BigInt m;
    int n;
    cin >> n >> str;
    m = str;
    cout << m % n << endl;
    return 0;
}
