#include <iostream>
#include <memory>

using namespace std;

struct Link {
    shared_ptr<Link> next;
};

int main() {
    auto a = make_shared<Link>();
    auto b = make_shared<Link>();
    a->next = b;
    a->next = a;
    return 0;
}

