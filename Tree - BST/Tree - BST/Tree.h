#pragma once
#include"Node.h"

template<typename T>
class Tree
{
protected:
	Node<T> *Root;
public:
	virtual void Insert(T) = 0;

	virtual void Print_LNR() = 0; //InOrder
	virtual void Print_RNL() = 0; //InOrder

	virtual void Print_NLR() = 0; //PreOrder
	virtual void Print_NRL() = 0; //PreOrder

	virtual void Print_LRN() = 0; //PostOrder
	virtual void Print_RLN() = 0; //PostOrder

	virtual void PrintTree() = 0; //Print Tree in Tree Order

	virtual void PrintAllLeaves() = 0; //Print All the Leaves of Tree

	virtual int NumbersOfLeaves() = 0;

	virtual int Prime_Counts() = 0;

	virtual int Even_Counts() = 0;

	virtual int Tree_Height() = 0;

	virtual T TREE_MINIMUM_Iteratively() = 0;
	virtual T TREE_MAXIMUM_Iteratively() = 0;

	virtual T TREE_MINIMUM_Recursively() = 0;
	virtual T TREE_MAXIMUM_Recursively() = 0;

	virtual T TREE_SEARCH(T Value) = 0;

	virtual void TreeTransplant(Node<T>*, Node<T>*) = 0;

	virtual Node<T>* TREE_SUCCESSOR(Node<T>*) = 0;
	virtual Node<T>* TREE_PREDECESSOR(Node<T>*) = 0;

	virtual void Delete(T Value) = 0;
	virtual void DeleteDuplicates() = 0;

	virtual void copyTree(Node<T>*, Node<T>*) = 0;
	virtual void destroyTree() = 0;







};


