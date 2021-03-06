#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *left;
	Node *right;

	Node(int value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

class Tree
{
private:
	Node *root;

	void addRecursive(Node *current, int value)
	{
		if (value < current->value)
		{
			if (current->left == NULL)
			{
				current->left = new Node(value, NULL, NULL);
			}
			else
			{
				addRecursive(current->left, value);
			}
		}
		else
		{
			if (current->right == NULL)
			{
				current->right = new Node(value, NULL, NULL);
			}
			else
			{
				addRecursive(current->right, value);
			}
		}
	}

	void removeRecursive(Node *current, int value)
	{
		if (value == current->value) // нямерихме елемента
		{
			// тук current е адреса на елемента за изтриване
			// на негово място трябва да сложим този вдясно от него
			// или (ако той не съществува) този вляво от него
			// ако изтрием current, неговия родител ще сочи към нищото
			// затова на адреса на current ще копираме заместника му
			// и ще изтрием (освободим) адреса на заместника

			Node *left = current->left;
			Node *right = current->right;

			if (right != NULL)
			{
				// вика копи конструктор по подразбиране
				// което ни върши работа, тъй като
				// искаме да копираме само адресите
				*current = *right;

				if (left != NULL)
				{
					Node *leftMost = getLetMostNode(right);
					leftMost->left = left;
				}

				delete right;
			}
			else
			{
				*current = *left;
				delete left;
			}
		}
		else if (value < current->value)
		{
			removeRecursive(current->left, value);
		}
		else
		{
			removeRecursive(current->right, value);
		}
	}

	// въври само наляво докато намери листо
	Node* getLetMostNode(Node *current)
	{
		while (current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}
public:
	Tree()
	{
		root = NULL;
	}

	void add(int element)
	{

		if (root == NULL)
		{
			root = new Node(element, NULL, NULL);
			return;
		}

		addRecursive(root, element);
	}

	void remove(int value)
	{
		if (root == NULL)
		{
			return;
		}

		removeRecursive(root, value);
	}
};

int main()
{
	Tree t;
	t.add(50);
	t.add(25);
	t.add(75);
	t.add(60);
	t.add(58);
	t.add(65);
	t.add(64);
	t.add(63);
	t.add(62);
	t.remove(60);

	system("pause");
	return 0;
}