/*************************************************************************
	> File Name: 7.operator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月24日 星期四 19时10分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct Data {
    Data(int x, int y) : x(x), y(y) {}
    int x, y;
};

Data operator+(Data &a, Data &b) {
    return Data(a.x + b.x, a.y + b.y);
}

ostream &operator<<(ostream &out, const Data &a) { 
    out << "class<Data> " << a.x << " " << a.y;
    return out;
}

int main() {
    Data a(2, 4), b(5, 6);
    cout << a + b << endl;
    return 0;
}
