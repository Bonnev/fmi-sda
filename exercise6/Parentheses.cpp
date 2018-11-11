/*
 * Напишете програма, която проверява
 * дали даден текст съдържа правилно
 * разположени скоби - (, [, {, <;
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
		// ако не съществуват елементи,
		// върни 0. В противен случай
		// върни стойността на най-горния
		return top == NULL ? 0 : top->value;
	}

	bool isEmpty()
	{
		return size == 0;
	}
};

bool isProper(string input)
{
	// тук ще държим всички отварящи скоби
	Stack stack = Stack();

	for (int i = 0; i < input.size(); i++)
	{
		// текущата отваряща скоба ли е?
		if (input[i] == '(' ||
			input[i] == '[' ||
			input[i] == '{' ||
			input[i] == '<')
		{
			stack.push(input[i]);
		}
		// щом не е, затваряща ли е?
		// (може да е и друг символ)
		else if (input[i] == ')' ||
			input[i] == ']' ||
			input[i] == '}' ||
			input[i] == '>')
		{
			// нека да видим последната
			// която сме сложили
			char top = stack.peek();

			// ако няма такава,
			// значи сме срещнали затваряща,
			// на която не отговаря отваряща.
			// вече знаем отговора
			if (top == 0)
			{
				return false;
			}

			// в противен случай,
			// ако скобата не си отговаря
			// със съответната отваряща,
			// отговорът е ясен
			switch (input[i])
			{
			case ')': if (top != '(') return false; break;
			case ']': if (top != '[') return false; break;
			case '}': if (top != '{') return false; break;
			case '>': if (top != '<') return false; break;
			}

			// ако сме стигнали дотук
			// значи всичко е наред с тези двойки
			// скоби. махаме последната отваряща
			// и продължаваме
			stack.pop();
		}

		// дори да сме имали достатъчно затварящи
		// за намерените отварящи, отново остава
		// случаят, в който отварящите са повече
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