#include <iostream>
#include "BST.h"
#include "Queue.h"

using namespace std;


void Task1() {

	BSTree<int> tree;

	tree.insert(10);
	tree.insert(9);
	tree.insert(8);
	tree.insert(20);
	tree.insert(30);
	tree.insert(11);
	tree.insert(7);
	tree.preorder(tree.root);
	cout << endl;
	tree.retrieve(20);
	tree.retrieve(200);


}
void Task2() {



	cout << "\n\n_____________________________________________________________\n";
	BSTree<int> tree;

	tree.insert(25);
	tree.insert(15);
	tree.insert(50);
	tree.insert(10);
	tree.insert(22);
	tree.insert(35);
	tree.insert(70);
	tree.insert(4);
	tree.insert(12);
	tree.insert(18);
	tree.insert(24);
	tree.insert(31);
	tree.insert(44);
	tree.insert(66);
	tree.insert(90);
	

	tree.levelOrder(tree.root);


}

int main() {

	Task1();
	Task2();


	return 0;
}

