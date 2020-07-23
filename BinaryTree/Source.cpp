#include <iostream>
using namespace std;
/************************************************************************************************************/
template<class T>
class Branch
{
public:
	T data;
	Branch* left;
	Branch* right;
	Branch() = default;
	Branch(T data = T(),
		   Branch* left = nullptr,
		   Branch* right = nullptr);
};
/************************************************************************************************************/
template<class T>
Branch<T>::Branch(T data, Branch* left, Branch* right) : data(data), left(left), right(right) {}
/************************************************************************************************************/
template<class T>
class BinaryTree
{
public:
	BinaryTree(void);
	void insert(T data);
	const T min(void) const;
	const T max(void) const;
	void inOrder(void) const;
private:
	Branch<T>* root;
	size_t _size;
protected:
	void insert(T data, Branch<T>* leaf);
	const Branch<T>* min(Branch<T>* leaf) const;
	const Branch<T>* max(Branch<T>* leaf) const;
	void inOrder(Branch<T>* leaf) const;
};
/************************************************************************************************************/
template<class T>
BinaryTree<T>::BinaryTree(void) : root(nullptr), _size(0) {}
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::insert(T data)
{
	if (this->root != nullptr){insert(data, this->root);}
	else {this->root = new Branch<T>(data);}
}
/************************************************************************************************************/
template<class T>
const T BinaryTree<T>::min(void) const
{
	if (this->root != nullptr) return min(this->root)->data;
	return T();
}
template<class T>
const T BinaryTree<T>::max(void) const
{
	if (this->root != nullptr) return max(this->root)->data;
	return T();
}
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::inOrder(void) const
{
	inOrder(this->root);
}
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::insert(T data, Branch<T>* leaf)
{
	if (data < leaf->data)
	{
		if (leaf->left != nullptr)
		{
			insert(data, leaf->left);
		}
		else
		{
			leaf->left = new Branch<T>(data);
		}
	}
	else
	{
		if (leaf->right != nullptr)
		{
			insert(data, leaf->right);
		}
		else
		{
			leaf->right = new Branch<T>(data);
		}
	}
}
/************************************************************************************************************/
template<class T>
const Branch<T>* BinaryTree<T>::min(Branch<T>* leaf) const
{
	if (leaf->left != nullptr) return min(leaf->left);
	else return leaf;
}
/************************************************************************************************************/
template<class T>
const Branch<T>* BinaryTree<T>::max(Branch<T>* leaf) const
{
	if (leaf->right != nullptr) return max(leaf->right);
	else return leaf;
}
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::inOrder(Branch<T>* leaf) const
{
	if (leaf != nullptr)
	{
		cout << leaf->data << " ";
		inOrder(leaf->left);
		inOrder(leaf->right);
	}
}
/************************************************************************************************************/
int main(int argc, char**argv[])
{
	BinaryTree<int>arr;
	arr.insert(40);
	for (int i = 0; i <= 100; ++i) arr.insert(i);
	cout << endl;
	arr.inOrder();
	cout << endl;
	cout << endl << arr.max() << " " << arr.min() << endl;
}


