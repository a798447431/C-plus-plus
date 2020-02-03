/*************************************************************************
	> File Name: kaobei.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月12日 星期六 18时44分31秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class A {
public:
    A() {
        n = 100;
        str = new char[n];
    }
    A(const A &obj) : A() {
        memcpy(str, obj.str, sizeof(char) * n);
        str[strlen(str) + 1] = '\0';
        str[strlen(str)] = 'a';
    }
    void set_str(const char *dest) {
        strcpy(str, dest);
    }
    void output_str() {
        cout << str << endl;
    }
    ~A() {
        printf("%p\n", str);
        fflush(stdout);
        delete[] str;
    }

private:
    int n;
    char *str;
};

int main() {
    A a;
    a.set_str("hello haizei");
    A b = a;
    a.output_str();
    b.output_str();
    return 0;
}
