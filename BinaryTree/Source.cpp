#include <iostream>

template<class T>
class Branch
{
public:
	T data;
	Branch* left;
	Branch* right;
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
private:
	Branch<T>* root;
	size_t _size;
protected:
	void insert(T data, Branch<T>* leaf);
};
/************************************************************************************************************/
template<class T>
BinaryTree<T>::BinaryTree(void) : root(nullptr), _size(0) {}
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::insert(T data)
{
	if (this->root != nullptr){insert(data, this->root);}
	else {this->root = new Branch(data);}
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
			leaf->left = new Branch(data);
		}
	}
	else if(data >= leaf->data)
	{
		if (leaf->right != nullptr)
		{
			insert(data, leaf->right);
		}
		else
		{
			leaf->right = new Branch(data);
		}
	}
	
}
/************************************************************************************************************/
int main(int argc, char**argv[])
{

}


