#include <iostream>

using namespace std;

struct point {
    int x;
    int y;
    point(int z) : x(z), y(z){}
    void print() {
        cout << this->x << " " << this->y << endl;
    }
};

int main() {
    auto p = new point[5]{1, 2, 3, 4, 5};
    p->print();
    delete[] p;
    return 0;
}

