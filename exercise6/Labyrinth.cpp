/*
 * Даден е лабиринт под формата на матрица
 * с нули (свободни полета) и единици (стени)
 * Напишете функция, която чрез подадени
 * лабиринта и дадена начална точка,
 * изписва всички възможни пътища навън
 * (до ръба на матрицата)
 */
#include <iostream>
#include <string>
#include <queue>
#include "Source.h"
using namespace std;

// Можехме и да ползваме 
// std::pair<,>
struct Coordinate
{
	int row;
	int column;

	Coordinate(int row, int column)
	{
		this->row = row;
		this->column = column;
	}
};

/*
 * масив, големина на масива, текуща позиция и пътят, през който сме минали 
 */
void findExit(int arr[5][5], int rows, int columns, int currentRow, int currentColumn, queue<Coordinate> path)
{
	// ако не е свободно тук, връщаме се
	if (arr[currentRow][currentColumn] > 0)
	{
		return;
	}

	// добавяме текущата позиция към пътя
	path.push(Coordinate(currentRow, currentColumn));

	// ако сме на границата (намерили сме изход
	if (currentRow == 0 || currentRow == rows - 1 ||
		currentColumn == 0 || currentColumn == columns - 1)
	{
		cout << "Found an exit!";
		// изпиши всички двойки координати от пътя
		while (!path.empty())
		{
			printf("(%d, %d)", path.front().row, path.front().column);
			path.pop();
		}
		return;
	}

	// маркираме текущата позиция като заета
	// за да не стъпваме отново върху нея (циклично)
	arr[currentRow][currentColumn] = 2;

	// продължаваме да се движим
	findExit(arr, rows, columns, currentRow - 1, currentColumn, path); // нагоре
	findExit(arr, rows, columns, currentRow + 1, currentColumn, path); // надолу
	findExit(arr, rows, columns, currentRow, currentColumn - 1, path); // наляво
	findExit(arr, rows, columns, currentRow, currentColumn + 1, path); // надясно

	// текущата позиция не беше част от текущия път (path)
	// но може да стане част от другия
	// затова я освобождаваме
	arr[currentRow][currentColumn] = 0;
}

int main()
{
	int arr[5][5] =
	{
		//     *
		{1, 1, 0, 1, 1},
		{1, 1, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 1, 0, 0, 1}, // *
		{1, 1, 1, 1, 1}
	};

	queue<Coordinate> path;
	findExit(arr, 5, 5, 3, 2, path);

	system("pause");
	return 0;
}