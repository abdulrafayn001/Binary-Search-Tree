#pragma once
#include"Tree.h"
#include"Node.h"
template<typename T>
class BST :public Tree<T>
{
	int Size;
	void InsertRecursively(Node<T>* &R, Node<T>* P, T V) // R = Root , P = Parent , V = Value
	{
		if (R == nullptr)
		{
			R = new Node<T>(V, P);
			return;
		}
		if (V < R->Data)
		{
			InsertRecursively(R->Left, R, V);
		}
		else
		{
			InsertRecursively(R->Right, R, V);
		}
	}

	void LNR_Recursively(Node<T>* X)
	{
		if (X != nullptr)
		{
			LNR_Recursively(X->Left);
			cout << X->Data << " ";
			LNR_Recursively(X->Right);
		}
	}
	void RNL_Recursively(Node<T>* X)
	{
		if (X != nullptr)
		{
			RNL_Recursively(X->Right);
			cout << X->Data << " ";
			RNL_Recursively(X->Left);
		}
	}

	void NLR_Recursively(Node<T>* X)
	{
		if (X != nullptr)
		{
			cout << X->Data << " ";
			NLR_Recursively(X->Left);
			NLR_Recursively(X->Right);
		}
	}
	void NRL_Recursively(Node<T>* X)
	{
		if (X != nullptr)
		{
			cout << X->Data << " ";
			NRL_Recursively(X->Right);
			NRL_Recursively(X->Left);
		}
	}

	void LRN_Recursively(Node<T>* X)
	{
		if (X != nullptr)
		{
			LRN_Recursively(X->Left);
			LRN_Recursively(X->Right);
			cout << X->Data << " ";
		}
	}
	void RLN_Recursively(Node<T>* X)
	{
		if (X != nullptr)
		{
			LRN_Recursively(X->Right);
			LRN_Recursively(X->Left);
			cout << X->Data << " ";
		}
	}

	void PrintTreeRecursively(Node<T>* X, int Distance) 
	{
		if (X != nullptr)
		{
			PrintTreeRecursively(X->Right, Distance + 1);
			for (int i = 0; i <= Distance; i++)
			{
				cout << "\t";
			}
			cout << X->Data << endl;
			PrintTreeRecursively(X->Left, Distance + 1);
		}
	}
	//??????????????/

	void PrintAllLeavesRecursively(Node<T>* X)
	{
		if (X == nullptr)
			return;
  
		if (X->Left == nullptr && X->Right == nullptr)
		{
			cout << X->Data << " ";
			return;
		}

		if (X->Left != nullptr)
			PrintAllLeavesRecursively(X->Left);
 
		if (X->Right != nullptr)
			PrintAllLeavesRecursively(X->Right);
	}

	int NumbersOfLeavesRecursively(Node<T> *Root)
	{
		if (Root == nullptr)
			return 0;
		else
		if (Root->Left == nullptr && Root->Left == nullptr)
			return 1;
		else
			return NumbersOfLeavesRecursively(Root->Right) + NumbersOfLeavesRecursively(Root->Left);
	}

	bool isPrime(int D)
	{
		for (int i = 2; i <= D / 2; ++i)
		{
			if (D % i == 0)
			{
				return false;
			}
		}
		return true;
	}
	int PrimeCountsRecursively(Node<T>* X)
	{
		if (X == nullptr)
			return 0;

		return (PrimeCountsRecursively(X->Left) + PrimeCountsRecursively(X->Right)) + isPrime(X->Data);
	}

	bool isEven(T D)
	{
		return D % 2 == 0;
	}
	int EvenCountsRecursively(Node<T>* X)
	{
		if (X == nullptr)
			return 0;

		return (EvenCountsRecursively(X->Left) + EvenCountsRecursively(X->Right)) + isEven(X->Data);
	}

	T Max_Value(T V1, T V2)
	{
		if (V1 > V2)
			return V1;
		return V2;
	}
	int TreeHeightRecursively(Node<T>* X)
	{
		if (X == nullptr)
			return 0;
		return Max_Value(TreeHeightRecursively(X->Left), TreeHeightRecursively(X->Right)) + 1;
	}

	bool RecursivelyPictoriallyAndValueEqual(Node<T>* BST_A, Node<T>* BST_B)
	{
		if (BST_A == nullptr && BST_B == nullptr)
			return true;
		if (BST_A == nullptr || BST_B == nullptr)
			return false;

		return BST_A->Data == BST_B->Data && RecursivelyPictoriallyAndValueEqual(BST_A->Left, BST_B->Left) && RecursivelyPictoriallyAndValueEqual(BST_A->Right, BST_B->Right);
	}
	bool RecursivelyValuesEqual(Node<T>* BST_A, Node<T>* BST_B)
	{
		if (BST_A == nullptr && BST_B == nullptr)
			return true;
		if (BST_A == nullptr || BST_B == nullptr)
			return false;

		return BST_A->Data == BST_B->Data && RecursivelyValuesEqual(BST_A->Left, BST_B->Right) && RecursivelyValuesEqual(BST_A->Right, BST_B->Left);
	}

	Node<T>* MAX_Node(Node<T>* N1, Node<T>* N2)
	{
		if (!N1)
			return N2;
		if (!N2)
			return N1;
		return ((N1->Data > N2->Data) ? N1 : N2);
	}
	Node<T>* MIN_Node(Node<T>* N1, Node<T>* N2)
	{
		if (!N1)
			return N2;
		if (!N2)
			return N1;
		return ((N1->Data < N2->Data) ? N1 : N2);
	}

	T TREE_MINIMUM_Iteratively(Node<T>* X)
	{
		while (true)
		{
			if (X->Left == nullptr)
			{
				return X->Data;
			}
			else
				X = X->Left;
		}
	}
	Node<T>* TREE_MINIMUM_Recursively(Node<T>* X)
	{
		if (X == nullptr)
			return X;
		return MIN_Node(MIN_Node(TREE_MINIMUM_Recursively(X->Left), TREE_MINIMUM_Recursively(X->Right)), X);
	}

	T TREE_MAXIMUM_Iteratively(Node<T>* X)
	{
		while (true)
		{
			if (X->Right == nullptr)
			{
				return X->Data;
			}
			else
				X = X->Right;
		}
	}
	Node<T>* TREE_MAXIMUM_Recursively(Node<T>* X)
	{
		if (X == nullptr)
			return X;
		return MAX_Node(MAX_Node(TREE_MAXIMUM_Recursively(X->Left), TREE_MAXIMUM_Recursively(X->Right)), X);
	}

	void DeleteDuplicates(Node<T>* R)
	{
		if (!R)
			return;

		if (R->Right)
		{
			if (SEARCH(R->Data, R->Right))
			{
				DeleteNode(R->Data, R->Right);
			}
		}
		DeleteDuplicates(R->Left);
		DeleteDuplicates(R->Right);
	}

	Node<T>* SEARCH(T Value, Node<T>* R)
	{
		while (R && Value != R->Data)
		{
			if (Value < R->Data)
				R = R->Left;
			else
				R = R->Right;
		}
		return R;
	}

	void DeleteNode(T Value, Node<T>* R)
	{
		Node<T>* DNode = SEARCH(Value, R);

		if (!DNode->Left)
		{
			TreeTransplant(DNode, DNode->Right);
		}
		else
		if (!DNode->Right)
		{
			TreeTransplant(DNode, DNode->Left);
		}
		else
		{
			Node<T>* tmp = TREE_MINIMUM_Recursively(DNode->Right);
			if (tmp->Parent != DNode)
			{
				TreeTransplant(tmp, tmp->Right);
				tmp->Right = DNode->Right;
				tmp->Right->Parent = tmp;
			}
			TreeTransplant(DNode, tmp);
			tmp->Left = DNode->Left;
			tmp->Left->Parent = tmp;
			Size--;
		}
	}

	void Clear(Node<T>* RootNode)
	{
		if (RootNode)              // if BST is not empty
		{
			Node<T> *Parent = nullptr;        // Node Pointer to Store Parent 

			if (!RootNode->Parent)
			{
				Parent = RootNode->Parent; // Store Parent of RootNode
			}

			if (RootNode->Left)    // if Left Node of is not NULL
			{
				Clear(RootNode->Left);  // Destroy Left Node
				if (Parent)       // if Parent is not NULL  
					Parent->Left = nullptr;   // Store NULL in Parent
			}
			else if (RootNode->Right)       // if Right Node of is not NULL
			{
				Clear(RootNode->Right);    // Destroy Right Node
				if (Parent)                 // if Parent is not NULL  
					Parent->Right = nullptr; // Store NULL in Parent
			}

			delete RootNode;                 // Delete Current Node
			RootNode = nullptr;				// Store NULL in RootNode
		}
	}


public:
	BST()
	{
		Size = 0;
	}

	void copyTree(Node<T>* Destination, Node<T>* Source)
	{
		if (Source == nullptr)
		{
			Destination = nullptr;
		}
		else
		{
			Destination = new Node<T>(Source->Data, Source->Parent);
			copyTree(Destination->Left, Source->Left);
			copyTree(Destination->Right, Source->Right);
		}
	}

	BST(const BST<T> &BST_B)
	{
		if (BST_B.Root == nullptr)
		{
			this->Root = nullptr;
		}
		else
		{
			copyTree(this->Root, BST_B.Root);
		}
	}

	void Insert(T Value)
	{
		Size++;
		InsertRecursively(Root, nullptr, Value);
	}
	//InOrder
	void Print_LNR()
	{
		LNR_Recursively(Root);
	}
	void Print_RNL()
	{
		RNL_Recursively(Root);
	}
	//PreOrder
	void Print_NLR()
	{
		NLR_Recursively(Root);
	}
	void Print_NRL()
	{
		NRL_Recursively(Root);
	}
	//PostOrder
	void Print_LRN()
	{
		LRN_Recursively(Root);
	}
	void Print_RLN()
	{
		RLN_Recursively(Root);
	}

	//Print Tree in Tree Order
	void PrintTree()
	{
		int Distance = 0;
		PrintTreeRecursively(Root, Distance);
	}

	// Print Level Order Traversal
	//????????????????????????????

	//Print All the Leaves of Tree
	void PrintAllLeaves()
	{
		PrintAllLeavesRecursively(Root);
	}

	//Counts Number of Primes in Integer Tree
	int Prime_Counts()
	{
		return PrimeCountsRecursively(Root);
	}

	//Counts Number of Even in Integer Tree
	int Even_Counts()
	{
		return EvenCountsRecursively(Root);
	}

	//Height of the Tree
	int Tree_Height()
	{
		return TreeHeightRecursively(Root);
	}

	//Both Trees are Exactly the Same (pictorially as well as value-wise)
	bool isEqual(Tree<T>* BST_A, Tree<T>* BST_B)
	{
		return RecursivelyPictoriallyAndValueEqual(BST_A->Root, BST_B->Root);
	}

	T TREE_MINIMUM_Iteratively()
	{
		return TREE_MINIMUM_Iteratively(Root);
	}
	T TREE_MINIMUM_Recursively()
	{
		return TREE_MINIMUM_Recursively(Root)->Data;
	}

	T TREE_MAXIMUM_Iteratively()
	{
		return TREE_MAXIMUM_Iteratively(Root);
	}
	T TREE_MAXIMUM_Recursively()
	{
		return TREE_MAXIMUM_Recursively(Root)->Data;
	}

	//Total Leaves in Tree
	int NumbersOfLeaves()
	{
		return NumbersOfLeavesRecursively(Root);
	}

	T TREE_SEARCH(T Value)
	{
		return SEARCH(Value, Root)->Data;
	}

	Node<T>* TREE_SUCCESSOR(Node<T>* R)
	{
		if (R->Right)
		{
			return TREE_MINIMUM_Recursively(R->Right);
		}
		else
		{
			Node<T>* Parent = R->Parent;
			while (!Parent && R == Parent->Right)
			{
				R = Parent;
				Parent = Parent->Parent;
			}
			return Parent;
		}
	}
	Node<T>* TREE_PREDECESSOR(Node<T>* R)
	{
		if (R->Left)
		{
			return TREE_MAXIMUM_Recursively(R->Left);
		}
		else
		{
			Node<T>* Parent = R->Parent;
			while (!Parent && R == Parent->Left)
			{
				R = Parent;
				Parent = Parent->Parent;
			}
			return Parent;
		}
	}

	void TreeTransplant(Node<T>* TreeA, Node<T>* TreeB)
	{
		if (!TreeA->Parent)
		{
			Root = TreeB;
		}
		else
		if (TreeA == TreeA->Parent->Left)
		{
			TreeA->Parent->Left = TreeB;
		}
		else
		{
			TreeA->Parent->Right = TreeB;
		}
		if (TreeB)
		{
			TreeB->Parent = TreeA->Parent;
		}
	}

	void Delete(T Value)
	{
		if (Root)
		{
			DeleteNode(Value, Root);
		}
	}

	void DeleteDuplicates()
	{
		DeleteDuplicates(Root);
	}

	void destroyTree()
	{
		if (Root)
		{
			Clear(Root);
			Root = nullptr;
			this->Size = 0;
		}
	}

	bool isEmpty()
	{
		return Size == 0;
	}
	
	~BST()
	{
		destroyTree();
	}
};

