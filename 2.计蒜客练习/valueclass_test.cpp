#include <iostream>

using namespace std;

/*
struct String {
private:
    char *buffer = nullptr;

public:
    String() : buffer{new char[]('\0')} {}
    String()(const char* theBuffer) : buffer{theBuffer} {}
    String()(const String& theString) : buffer{theString.buffer} {}
    ~String() {
        delete[] buffer;
    }
};
*/

class X {
public:
    void Print()&& {
        cout << "X&" << endl;
    }
};

X GetX() {
    return {};
}

int main() {
    /*
    String a = "This is a string";
    String b = a;
    String c;
    c = b;
    */
    GetX().Print();
    return 0;
}

