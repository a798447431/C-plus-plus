#include <iostream>

using namespace std;

struct Vector {
    int x;
    int y;
};

int ReadVector(Vector v, int Vector::* p) {
    return v.*p;
}

int main() {
    Vector v{1, 2};
    /*
    int Vector::* px = &Vector::x;
    int Vector::* py = &Vector::y;
    cout << v.*px << endl;
    cout << v.*py << endl;
    */
    cout << ReadVector(v, &Vector::x) << endl;
    cout << ReadVector(v, &Vector::y) << endl;
    return 0;
}

