#include<iostream>
#include"AvlTree.h"
using namespace std;
int main()
{

    AVL obj;
    /* Constructing tree given in
    the above figure */
    obj.root = obj.insert(10, obj.root);

    obj.root = obj.insert(20, obj.root);
    obj.root = obj.insert(30, obj.root);
    obj.root = obj.insert(40, obj.root);
    obj.root = obj.insert(50, obj.root);
    obj.root = obj.insert(60, obj.root);
    obj.preordertraversal(obj.root);

    return 0;
}