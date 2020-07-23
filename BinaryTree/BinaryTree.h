#pragma once
#ifndef _BINARYTREE_
#define _BINARYTREE_
/************************************************************************************************************/
#include <iostream>
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
	void preOrder(void) const;
	void remove(T key);
	const bool empty(void) const;
	const bool search(T key) const;
	const size_t size(void) const;
private:
	Branch<T>* root;
	size_t _size;
protected:
	void insert(T data, Branch<T>* leaf);
	Branch<T>* min(Branch<T>* leaf) const;
	Branch<T>* max(Branch<T>* leaf) const;
	void inOrder(Branch<T>* leaf) const;
	void preOrder(Branch<T>* leaf) const;
	Branch<T>* remove(T key, Branch<T>* leaf);
	Branch<T>* search(T key, Branch<T>* leaf) const;
};
/************************************************************************************************************/
template<class T>
BinaryTree<T>::BinaryTree(void) : root(nullptr), _size(0) {}
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::insert(T data)
{
	if (this->root != nullptr) { insert(data, this->root); }
	else { this->root = new Branch<T>(data); }
	++this->_size;
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
void BinaryTree<T>::inOrder(void) const { inOrder(this->root); }
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::preOrder(void) const { preOrder(this->root); }
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::remove(T key)
{
	this->root = remove(key, this->root);
	--this->_size;
}
/************************************************************************************************************/
template<class T>
const bool BinaryTree<T>::empty(void) const { return this->root != nullptr ? false : true; }
/************************************************************************************************************/
template<class T>
const bool BinaryTree<T>::search(T key) const
{
	return search(key, this->root) ? true : false;
}
/************************************************************************************************************/
template<class T>
const size_t BinaryTree<T>::size(void) const { return this->_size; }
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
	else if (data > leaf->data)
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
Branch<T>* BinaryTree<T>::min(Branch<T>* leaf) const
{
	if (leaf->left != nullptr) return min(leaf->left);
	else return leaf;
}
/************************************************************************************************************/
template<class T>
Branch<T>* BinaryTree<T>::max(Branch<T>* leaf) const
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
		std::cout << leaf->data << " ";
		inOrder(leaf->left);
		inOrder(leaf->right);
	}
}
/************************************************************************************************************/
template<class T>
void BinaryTree<T>::preOrder(Branch<T>* leaf) const
{
	if (leaf != nullptr)
	{
		preOrder(leaf->left);
		preOrder(leaf->right);
		std::cout << leaf->data << " ";
	}
}
/************************************************************************************************************/
template<class T>
Branch<T>* BinaryTree<T>::remove(T key, Branch<T>* leaf)
{
	Branch<T>* tmp;
	if (leaf == nullptr) return nullptr;
	else if (key < leaf->data) { remove(key, leaf->left); }
	else if (key > leaf->data) { remove(key, leaf->right); }
	else if (leaf->left != nullptr && leaf->right != nullptr)
	{
		tmp = min(leaf->right);
		leaf->data = tmp->data;
		leaf->right = remove(leaf->data, leaf->right);
	}
	else
	{
		tmp = leaf;
		if (leaf->left == nullptr) leaf = leaf->right;
		else if (leaf->right == nullptr) leaf = leaf->left;
		delete tmp;
	}
	return leaf;
}
/************************************************************************************************************/
template<class T>
Branch<T>* BinaryTree<T>::search(T key,Branch<T>* leaf) const
{
	if (leaf == nullptr)        return nullptr;
	else if (key == leaf->data) return leaf;
	else if (key < leaf->data)  return search(key, leaf->left);
	else if (key > leaf->data)  return search(key, leaf->right);
}
/************************************************************************************************************/
#endif // !_BINARYTREE_
