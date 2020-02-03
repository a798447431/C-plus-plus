/*************************************************************************
	> File Name: 3.class_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月12日 星期六 10时07分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public:
    /*
    Point() : _x(0), _y(0) {
        cout << "constructor" << endl;
        cout << this << endl;
    } //_x() 相当于整形类对象 
    */
    Point();
    Point(int x, int y);
    Point(const Point &p);
    ~Point();
    int x() const;
    int y() const;
    int z() const;
    static int cnt();

private:
    int _x, _y; 
    mutable int _z;
    static int _cnt;
};

Point::Point() {
    this->_x = 0, this->_y = 0, this->_z = 0;
    cout << "constructor" << endl;
    cout << this << endl;
    this->_cnt++;
}

Point::Point(int x, int y) : Point() {
    this->_x = x, this->_y = y;    
    cout << "constructor with parameters" << endl;
    cout << this << endl;
}

Point::Point(const Point &p) : Point() {
    this->_x = p.x();
    this->_y = p.y();
    cout << "copy constructor" << endl;
    cout << this << endl;
}

Point::~Point() {
    cout << "distructor" << endl;
    cout << this << endl;
    this->_cnt -= 1;
}

int Point::x() const { this->_z += 1;  return this->_x; }
int Point::y() const { return this->_y; }
int Point::z() const { return this->_z; }
int Point::cnt() { return Point::_cnt; }
int Point::_cnt = 0;

int main() {
    Point p1, p2(2, 3), p3(p2);
    cout << p1.x() << " " << p1.y() << endl;
    cout << p2.x() << " " << p2.y() << endl;
    cout << p3.x() << " " << p3.y() << endl;
    cout << "p1.x_cnt = " << p1.z() << endl;
    cout << "p2.x_cnt = " << p2.z() << endl;
    cout << "p3.x_cnt = " << p3.z() << endl;
    cout << Point::cnt() << endl;
    return 0;
}
