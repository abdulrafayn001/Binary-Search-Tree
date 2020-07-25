#include"BST.h"
#include<string>
#include<iostream>
using namespace std;

void DesignLogo();
int options();
template<typename T>
void optionOne(BST<T> &T);

void menu();
int main()
{
	menu();
	return 0;
}

void DesignLogo()
{
	cout << "\t\t\t\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~" << endl;
	cout << "\t\t\t\t                   Binary Search Tree          " << endl;
	cout << "\t\t\t\t\t~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~" << endl;
}
int options()
{
	cout << "\t\t\t\t\t\t++++++++++++++++++++++" << endl;
	cout << "\t\t\t\t\t\t+        MENU        +" << endl;
	cout << "\t\t\t\t\t\t++++++++++++++++++++++" << endl << endl;
	int choice = 0;
	cout << "  \t\t\t\tPress 1 to insert values in the tree" << endl;
	cout << "  \t\t\t\tPress 2 to delete a value from the tree" << endl;
	cout << "  \t\t\t\tPress 4 for pre - order traversal NLR" << endl;
	cout << "  \t\t\t\tPress 5 for in - order traversal LNR" << endl;
	cout << "  \t\t\t\tPress 6 for post - order traversal LRN" << endl;
	cout << "  \t\t\t\tPress 7 for pre - order traversal 2 NRL" << endl;
	cout << "  \t\t\t\tPress 8 for in - order traversal 2 RNL" << endl;
	cout << "  \t\t\t\tPress 9 for post - order traversal 2 RLN" << endl;
	cout << "  \t\t\t\tPress 10 to destroy the tree(all nodes must be deleted)" << endl;
	cout << "  \t\t\t\tPress 11 to Print All Leaves in the tree" << endl;
	cout << "  \t\t\t\tPress 12 to count number of primes in Tree" << endl;
	cout << "  \t\t\t\tPress 13 to count height of tree" << endl;
	cout << "  \t\t\t\tPress 14 to EXIT" << endl;
	cout << "  \t\t\t\t\t\t****************" << endl;
	cout << "  \t\t\t\t\t\t    Choice : ";
	cin >> choice;
	cout << "  \t\t\t\t\t\t****************" << endl;
	cout << endl;
	return choice;
}

template<typename T>
void optionOne(BST<T> &Tree)
{
	cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
	cout << "\t\t\t\t\t\tINSERT VALUES IN TREE" << endl << endl;
	cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
	T V;
	char YorN = { '\0' };
	do
	{
		YorN = { '\0' };
		cout << endl;
		cout << "  \t\t\t\t\t\t  Enter Value: ";
		cin >> V;
		cout << endl;

		Tree.Insert(V);

		do
		{
			cout << "\t\t\t\t Do you want to insert more value?   (y/n)  ....";
			cin >> YorN;
		} while (!(YorN == 'N' || YorN == 'n' || YorN == 'Y' || YorN == 'y'));


	} while (!(YorN == 'N' || YorN == 'n'));
	cout << endl << endl;
	YorN = { '\0' };
	do
	{
		cout << "\t\t\t\t Do you want to ptint tree?   (y/n)  ....";
		cin >> YorN;
	} while (!(YorN == 'N' || YorN == 'n' || YorN == 'Y' || YorN == 'y'));
	if (YorN == 'Y' || YorN == 'y')
	{
		cout << endl << endl;
		Tree.PrintTree();
	}
	cout << "     \t\t\t<-------------------------------------------------------->" << endl;
	cout << endl << endl;

}

template<typename T>
void optionTwo(BST<T> &Tree)
{
	if (!Tree.isEmpty())
	{
		cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
		cout << "\t\t\t\t\t\t    DELETE VALUES    " << endl << endl;
		cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
		T V;
		char YorN = { '\0' };
		do
		{
			YorN = { '\0' };
			cout << endl;
			cout << "\t\t\t\t\t\tEnter Value to Delete: ";
			cin >> V;
			cout << endl;

			Tree.Delete(V);

			do
			{
				cout << "\t\t\t\t Do you want to delete more value?   (y/n)  ....";
				cin >> YorN;
			} while (!(YorN == 'N' || YorN == 'n' || YorN == 'Y' || YorN == 'y'));


		} while (!(YorN == 'N' || YorN == 'n'));
		cout << endl << endl;
		YorN = { '\0' };
		do
		{
			cout << "\t\t\t\t Do you want to ptint tree?   (y/n)  ....";
			cin >> YorN;
		} while (!(YorN == 'N' || YorN == 'n' || YorN == 'Y' || YorN == 'y'));
		if (YorN == 'Y' || YorN == 'y')
		{
			cout << endl << endl;
			Tree.PrintTree();
		}
		cout << "     \t\t\t<-------------------------------------------------------->" << endl;
	}
	else
	{
		cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
		cout << "\t\t\t\t\t\t Insert Before Deletion " << endl;
		cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
	}
	cout << endl << endl;
}

void menu()
{
	string fileName;
	char YorN = { '\0' };
	BST<int> T, T2;
	int V;
	int op = { 0 };
	DesignLogo();
	do
	{
		op = options();
		switch (op)
		{
		case 1:
			optionOne(T);
			break;
		case 2:
			optionTwo(T);
			break;
		case 4:
			if (!T.isEmpty())
			{
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << "\t\t\t\t\t\t         NLR         " << endl << endl;
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << endl;
				T.Print_NLR();
			}
			else
			{
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
				cout << "\t\t\t\t\t\t Insert Before Traversal " << endl;
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
			}
			break;
		case 5:
			if (!T.isEmpty())
			{
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << "\t\t\t\t\t\t         LNR         " << endl << endl;
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << endl;
				T.Print_LNR();
			}
			else
			{
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
				cout << "\t\t\t\t\t\t Insert Before Traversal " << endl;
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
			}
			break;
		case 6:
			if (!T.isEmpty())
			{
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << "\t\t\t\t\t\t         LRN         " << endl << endl;
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << endl;
				T.Print_LRN();
			}
			else
			{
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
				cout << "\t\t\t\t\t\t Insert Before Traversal " << endl;
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
			}
			break;
		case 7:
			if (!T.isEmpty())
			{
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << "\t\t\t\t\t\t         NRL         " << endl << endl;
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << endl;
				T.Print_NRL();
			}
			else
			{
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
				cout << "\t\t\t\t\t\t Insert Before Traversal " << endl;
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
			}
			break;
		case 8:
			if (!T.isEmpty())
			{
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << "\t\t\t\t\t\t         RNL         " << endl << endl;
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << endl;
				T.Print_RNL();
			}
			else
			{
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
				cout << "\t\t\t\t\t\t Insert Before Traversal " << endl;
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
			}
			break;
		case 9:
			if (!T.isEmpty())
			{
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << "\t\t\t\t\t\t         RLN         " << endl << endl;
				cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
				cout << endl;
				T.Print_RLN();
			}
			else
			{
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
				cout << "\t\t\t\t\t\t Insert Before Traversal " << endl;
				cout << "\t\t\t\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
			}
			break;
		case 10:
			cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
			cout << "\t\t\t\t\t\t    TREE DESTROYED   " << endl << endl;
			cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
			T.destroyTree();
			break;
		case 11:
			cout << "\t\t\t\t\t\t///////////////////////////////" << endl << endl;
			cout << "\t\t\t\t\t\t PRINT ALL LEAVES  " << endl << endl;
			cout << "\t\t\t\t\t\t///////////////////////////////" << endl << endl;
			T.PrintAllLeaves();
			do
			{
				cout << "\t\t\t\t Do you want to ptint tree?   (y/n)  ....";
				cin >> YorN;
			} while (!(YorN == 'N' || YorN == 'n' || YorN == 'Y' || YorN == 'y'));
			if (YorN == 'Y' || YorN == 'y')
			{
				cout << endl << endl;
				T.PrintTree();
			}
			break;
		case 12:
			cout << "\t\t\t\t\t\t///////////////////////////////" << endl << endl;
			cout << "\t\t\t\t\t\t Counts Number of Primes  " << endl << endl;
			cout << "\t\t\t\t\t\t///////////////////////////////" << endl << endl;
			
			cout << "\t\t\t\t Number of Primes in Tree are " << T.Prime_Counts() << endl;
			do
			{
				cout << "\t\t\t\t Do you want to ptint tree?   (y/n)  ....";
				cin >> YorN;
			} while (!(YorN == 'N' || YorN == 'n' || YorN == 'Y' || YorN == 'y'));
			if (YorN == 'Y' || YorN == 'y')
			{
				cout << endl << endl;
				T.PrintTree();
			}
			break;
		case 13:
			cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
			cout << "\t\t\t\t\t\t      Tree Height     " << endl << endl;
			cout << "\t\t\t\t\t\t/////////////////////" << endl << endl;
			cout << "\t\t\t\t Height of Tree is " << T.Tree_Height() << endl;

			do
			{
				cout << "\t\t\t\t Do you want to ptint tree?   (y/n)  ....";
				cin >> YorN;
			} while (!(YorN == 'N' || YorN == 'n' || YorN == 'Y' || YorN == 'y'));
			if (YorN == 'Y' || YorN == 'y')
			{
				cout << endl << endl;
				T.PrintTree();
			}

			cout << endl << endl;
			break;
		default:
			break;
		}

	} while (op != 14);
}