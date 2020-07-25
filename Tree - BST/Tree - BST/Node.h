#pragma once
template<typename T>
struct Node
{
	T Data;
	Node* Left;
	Node* Right;
	Node* Parent;
public:
	Node()
	{
		Left = nullptr;
		Right = nullptr;
		Parent = nullptr;
	}

	Node(T D, Node* P)
	{
		Data = D;
		Left = nullptr;
		Right = nullptr;
		Parent = P;
	}

	~Node(){}
};
