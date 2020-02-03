#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Node;
extern Node* CreateNode();
extern void DestroyNode(Node* node);

struct Node {
private:
    Node() = default;
    ~Node() = default;

public:
    friend Node *CreateNode();
    friend void DestroyNode(Node* node);
    void Introduce() {
        cout << "我是Node." <<  endl;
    }
};

Node *CreateNode() {
    return new Node;
}

void DestroyNode(Node *node) {
    delete node;
}

int main() {
    auto node = CreateNode();
    node->Introduce();
    DestroyNode(node);
    return 0;
}

