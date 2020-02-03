/*************************************************************************
	> File Name: 2.class.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年09月02日 星期一 14时14分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public :
    /*
    Point() {
        this->_x = 0; 
        this->_y = 0;
    }
    Point(int x, int y) {
        this->_x = x;
        this->_y = y;
    }
    */
    // 初始化列表
  // 构造函数　初始化列表　 {}内:构造逻辑
    // 当执行构造逻辑时，当前对象就已经构造完了
    Point() : _x(0), _y(0), _cnt(0) {
        Point::total += 1; //Point:: c++命名空间的机制 等价于this->total
        cout << "Point constructor : " << this << endl;
    }

    // 委托构造
    Point(int x, int y) : Point() {
   // Point(int x, int y) : _x(x), _y(y), _cnt(0) {
        this->_x = x;
        this->_y = y;
        cout << "Point constructor with parameters : " << this << endl;
    }

    // 拷贝构造　引用另外一个同类型对象
    Point(const Point &b) : Point() { //在该方法内部不改b的值
        //this 指向当前对象　特殊关键字指向当前对象地址 成员属性内部特殊的指针变量
        cout << "Point copy constructor : " << this << endl;
        this->_x = b._x;
        this->_y = b._y;
        this->_cnt = b._cnt;
    }
    int getX() const { 
        this->_cnt += 1;
        return this->_x; 
    } 
    int getY() const { return this->_y; }

    static int getTotal() { return Point::total; }
    
    ~Point() {
        this->total -= 1;
        cout << "Point destructor" << endl;
    }

private:
    int _x, _y;
    mutable int _cnt;

    static int total; //只是声明，还没有定义
};

int Point::total = 0;

void func(Point &b) {
    cout << "b : " << (&b) << endl;
    return ;
}

ostream& operator<<(ostream &out, const Point &p) {
    out << "(" << p.getX() << ", " << p.getY() << ")";
    return out;
}

void func2() {
    Point a, b, c;
}

int main() {
    const Point p(4, 5);
    //Point p1; //定义了有参函数后，无参函数就会被删除
    Point p1(p), p2(p1);
    func(p1);
    func2();
    //cout 对应的类重载了左移运算符 cout是个对象
    cout << p1 << " " << p1 << endl;
    //cout << p1 == (cout.operator<<(p1)) 返回值返回cout本身
    cout << Point::getTotal() << endl;
    return 0;
}
