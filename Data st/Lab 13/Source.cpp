#include <iostream>
#include "BST.h"

using namespace std;


int main() {


	BSTree<int> t;

	t.insert(100);
	t.insert(50);
	t.insert(200);
	t.insert(150);
	t.insert(300);

	t.preorder(t.root);
	t.deleteData(200);
	cout << endl << t.getMin(t.root) << endl;
	t.preorder(t.root);


	return 0;
}