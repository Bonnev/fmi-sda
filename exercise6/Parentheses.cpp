/*
 * �������� ��������, ����� ���������
 * ���� ����� ����� ������� ��������
 * ����������� ����� - (, [, {, <;
 */
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	char value;
	Node *next;
};

class Stack
{
private:
	Node *top;
	size_t size;

public:
	Stack()
	{
		top = NULL;
		size = 0;
	}

	void push(char character)
	{
		Node *newTop = new Node();
		newTop->value = character;
		newTop->next = top;
	
		top = newTop;
		size++;
	}

	char pop()
	{
		if (top == NULL)
		{
			return 0;
		}

		char value = top->value;
		Node *nextTop = top->next;
		
		delete top;
		top = nextTop;
		size--;

		return value;
	}

	char peek()
	{
		// ��� �� ����������� ��������,
		// ����� 0. � �������� ������
		// ����� ���������� �� ���-������
		return top == NULL ? 0 : top->value;
	}

	bool isEmpty()
	{
		return size == 0;
	}
};

bool isProper(string input)
{
	// ��� �� ������ ������ �������� �����
	Stack stack = Stack();

	for (int i = 0; i < input.size(); i++)
	{
		// �������� �������� ����� �� �?
		if (input[i] == '(' ||
			input[i] == '[' ||
			input[i] == '{' ||
			input[i] == '<')
		{
			stack.push(input[i]);
		}
		// ��� �� �, ��������� �� �?
		// (���� �� � � ���� ������)
		else if (input[i] == ')' ||
			input[i] == ']' ||
			input[i] == '}' ||
			input[i] == '>')
		{
			// ���� �� ����� ����������
			// ����� ��� �������
			char top = stack.peek();

			// ��� ���� ������,
			// ����� ��� �������� ���������,
			// �� ����� �� �������� ��������.
			// ���� ����� ��������
			if (top == 0)
			{
				return false;
			}

			// � �������� ������,
			// ��� ������� �� �� ��������
			// ��� ����������� ��������,
			// ��������� � ����
			switch (input[i])
			{
			case ')': if (top != '(') return false; break;
			case ']': if (top != '[') return false; break;
			case '}': if (top != '{') return false; break;
			case '>': if (top != '<') return false; break;
			}

			// ��� ��� �������� �����
			// ����� ������ � ����� � ���� ������
			// �����. ������ ���������� ��������
			// � ������������
			stack.pop();
		}

		// ���� �� ��� ����� ���������� ���������
		// �� ���������� ��������, ������ ������
		// �������, � ����� ���������� �� ������
		return stack.isEmpty();
	}
}

int main()
{
	string input;
	getline(cin, input);
	
	cout << isProper(input);

	system("pause");
	return 0;
}