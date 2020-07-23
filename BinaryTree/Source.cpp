#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main(int argc, char**argv[])
{
	BinaryTree<int>arr;
	arr.insert(40);
	for (int i = 0; i <= 100; ++i) arr.insert(i);
	cout << endl;
	arr.inOrder();
	cout << endl << endl << endl;
	arr.preOrder();
	cout << endl << endl << endl;
	arr.remove(40);
	arr.preOrder();
}
/************************************************************************************************************/

