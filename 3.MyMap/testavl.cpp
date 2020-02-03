/*************************************************************************
	> File Name: testavl.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月13日 星期三 20时41分18秒
 ************************************************************************/

#include "my_AVL.h"

int main() {
    AVLTree<int, string> tree;
    tree.insert(pair<int, string>(1, "string"));
    //tree.insert(pair<int, string>(1, "string"));
    //tree.insert(pair<int, string>(2, "hello"));
    //tree.insert(pair<int, string>(2, "hello"));
    //tree.insert(pair<int, string>(3, "world"));
    //tree.insert(pair<int, string>(4, "haizei"));
    tree.output();
    return 0;
}


