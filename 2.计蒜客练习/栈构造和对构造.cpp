#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point a{1, 2};
    Point b = a;
    Point *c = new Point{1, 2};
    Point *d = c;
    a.x = 10;
    c->x = 10;
    cout << b.x << ", " << d->x << endl;
    delete c;
    return 0;
}

