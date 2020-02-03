/*************************************************************************
	> File Name: 11.move_constructor_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月10日 星期日 15时53分47秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct BigInt {
    BigInt() {
        n = 1;
        data = new int[100];
        data[0] = 0; 
    }
    BigInt(int x) {
        data = new int[100];
        data[0] = x;
        n = 1;
        proccess_digit();
    }
    BigInt(BigInt &&a) {
        data = a.data;
        n = a.n;
        a.data = nullptr;
    }
    BigInt operator+(const BigInt &a) {
        BigInt ret;
        ret += a;
        ret += (*this);
        return ret;
    }
    void operator+=(const BigInt &a) {
        for(int i = 0; i < a.n; i++) {
            if (i == n) data[i] = 0, n += 1;
            data[i] += a.data[i];
        }
        proccess_digit();
        return ;
    }
    void proccess_digit() {
        for (int i = 0; i < n; i++) {
            if (data[i] < 10) continue;
            if (i + 1 == n) n += 1, data[i + 1] = 0;
            data[i + 1] += data[i] / 10;
            data[i] %= 10;
        }
        return ;
    }
    ~BigInt() {
        if (data == nullptr) return ;
        delete data;
        data = nullptr;
    }
    int *data, n;
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.n - 1; i >= 0; i--) {
        out << a.data[i];
    }
    return out;
}

int main() {
    BigInt b = 123, c = 456;
    BigInt a = b + c;
    cout << a << endl;
    return 0;
}
