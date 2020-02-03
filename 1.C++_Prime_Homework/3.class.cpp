/*************************************************************************
	> File Name: 3.class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月10日 星期四 20时07分04秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Point{
public:
    Point() : _x(0), _y(0) {
        cout << "constructor" << endl;
        cout << this << endl;
    }
    Point(int x, int y) : _x(x), _y(y){
        cout << "constructor with parameters" << endl;
        cout << this << endl;
    }
    Point(const Point &p) {
        _x = p._x;
        _y = p._y;
        cout << "copy constructor" << endl;
        cout << this << endl;
    }
    int x() { return _x; }
    int y() { return _y; }
    ~Point() {
        cout << "destructor" << endl;
        cout << this << endl;
    }
    static int cnt() { return Point::_cnt; }

private:
    int _x, _y;
    static int _cnt;
};

int main() {
    Point p1, p2(2, 3), p3(p2);
    cout << p1.x() << p1.y() << endl;
    cout << p2.x() << p2.y() << endl;
    cout << p3.x() << p3.y() << endl;
    cout << Point::cnt() << endl;
    return 0;
}
