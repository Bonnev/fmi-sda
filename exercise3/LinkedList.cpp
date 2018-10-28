#include <iostream>
using namespace std;

// Един елемент от списъка трябва да
// съдържа повече от просто стойността.
// Той трябва да съдържа и връзката
// със следващия елемент.
struct Node
{
	int value; // стойността на елемента
	Node *next; // указател към следващия елемент
	// Ако тук имахме и Node *previous; списъкът
	// щеше да е "двусвързан" (Doubly-Linked)
	
	// За улеснение (незадължително)
	Node(int value, Node *next)
	{
		this->value = value;
		this->next = next;
	}

	// Трябва ли ни голямата четворка тук?
	// Няма нужда! value ще си се изтрие автоматично
	// както и next (или поне член-променливата).
	// Елементът, към който сочи next няма да се изтрие,
	// но и него можем да изтрием директно чрез класа.
}

// Ето го и класа. Ако беше двойно свързан,
// you know what to do ;)
class LinkedList
{
private:
	Node *start; // начало на списъка
	Node *end; // край на списъка
	size_t size; // размера на списъка
public:
	// В конструктора просто нулираме
	// началото и края
	LinkedList()
	{
		start = NULL;
		end = NULL;
		size = 0;
	}

	// Можем и да имаме конструктор,
	// който да ни създава списък от масив
	LinkedList(int *array, int count)
	{
		this(); // нулираме start & end

		// за всеки елемент в масива
		for(int i = 0; i < count; i++)
		{
			// го добавяме в края на списъка
			append(array[i]);
		}

		size = count;
	}

	// добавя число в края на списъка;
	// може да се казва и addToEnd
	void append(int number)
	{
		// създаваме новия елемент
		Node *newElement = new Node(number, NULL);

		if(end == NULL)	// ако списъкът е празен
		{
			// началото и краят са този нов елемент
			start = newElement;
			end = newElement;
			size = 1;
		}
		else // ако вече има елементи в списъка
		{
			// след текущия последен елемент
			// следва новия елемент
			end->next = newElement;

			// и новият елемент става последен
			end = newElement;

			// размерът току-що се увеличи
			size++;
		}
	}

	// добавя елемент в началото на списъка
	// може да се казва и addToStart
	void prepend(int number)
	{
		// създаваме новия елемент
		Node *newElement = new Node(number, start); // а ако start == NULL?

		if(start == NULL)
		{
			start = newElement;
			end = newElement;
		}
		else
		{
			// newElement->next = start; трябва ли ни?
			
			// и новият ни елемент става първи
			start = newElement;

			// размерът току-що се увеличи
			size++;
		}
	}

	// добавя елемент на специфичен индекс
	// тоест на този индекс искаме вече да е този елемент
	// тоест ще го добавим ПРЕДИ текущия index;
	// може да се казва и addAt;
	// връща false ако операцията е невъзможна
	bool insertAt(int index, int number)
	{
		// създаваме новия елемент
		Node *newElement = new Node(number, NULL); // не знаем кой е next все още

		// ако списъкът е празен
		if(start == NULL)
		{
			// и ние искаме да добавим на първа позиция
			if(index == 0)
			{
				// като prepend()
				start = newElement;
				end = newElement;
				size = 1;
				return true;
			}
			else // ако искаме да добавим на друга позиция
			{
				// това е невъзможно
				return false;
			}
		}

		// трябва да стигнем до елемента на индекс index
		// тоест да минем през всички предишни
		Node *current = start;
		for(int i = 0; i < index-1; i++) // index-1 пъти
		{
			// щом сме още в цикъла, значи трябва
			// да продължим да се местим надясно;
			// ако обаче няма повече накъде
			if(current->next == NULL)
			{
				// значи операцията
				// е невъзможна
				return false;
			}

			current = current->next; // местим current надясно
		}
		// тук current вече е елементът на индекс index-1

		// след новия елемент трябва да е този
		// на текущия index
		newElement->next = current->next;

		// след index-1 следва новия index
		current->next = newElement;

		// размерът току-що се увеличи
		size++;

		// всичко е точно
		return true;
	}

	bool removeLast()
	{
		if(end == NULL)
		{
			return false;
		}

		// else??
	}
}

int main()
{

	return 0;
}

