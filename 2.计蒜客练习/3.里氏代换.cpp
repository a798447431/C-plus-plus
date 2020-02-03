#include <iostream>

using namespace std;

class Bird {
public:
    bool fly() {
        return true;
    };
    int getVelocity(){
        return this->velocity;
    }
private:
    int velocity;
};

class Ostrich : public Bird {
    bool fly() {
        return false;
    };
    int getVelocity() {
        return 0;
    }
};

int main() {
    Bird *bird = new Ostrich;
    cout << "h:" << 3000 / bird->getVelocity() << endl;
    return 0;
}

