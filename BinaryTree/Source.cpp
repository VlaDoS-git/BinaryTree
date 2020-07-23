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

template<class T>
Branch<T>::Branch(T data, Branch* left, Branch* right) : data(data), left(left), right(right) {}

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
};

int main(int argc, char**argv[])
{

}

template<class T>
BinaryTree<T>::BinaryTree(void) : root(nullptr), _size(0) {}

template<class T>
void BinaryTree<T>::insert(T data)
{
	if(this->root != nullptr)
}
