/*
 * ����� � �������� ��� ������� �� �������
 * � ���� (�������� ������) � ������� (�����)
 * �������� �������, ����� ���� ��������
 * ��������� � ������ ������� �����,
 * ������� ������ �������� ������ �����
 * (�� ���� �� ���������)
 */
#include <iostream>
#include <string>
#include <queue>
#include "Source.h"
using namespace std;

// ������� � �� �������� 
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
 * �����, �������� �� ������, ������ ������� � �����, ���� ����� ��� ������ 
 */
void findExit(int arr[5][5], int rows, int columns, int currentRow, int currentColumn, queue<Coordinate> path)
{
	// ��� �� � �������� ���, ������� ��
	if (arr[currentRow][currentColumn] > 0)
	{
		return;
	}

	// �������� �������� ������� ��� ����
	path.push(Coordinate(currentRow, currentColumn));

	// ��� ��� �� ��������� (�������� ��� �����
	if (currentRow == 0 || currentRow == rows - 1 ||
		currentColumn == 0 || currentColumn == columns - 1)
	{
		cout << "Found an exit!";
		// ������ ������ ������ ���������� �� ����
		while (!path.empty())
		{
			printf("(%d, %d)", path.front().row, path.front().column);
			path.pop();
		}
		return;
	}

	// ��������� �������� ������� ���� �����
	// �� �� �� �������� ������ ����� ��� (��������)
	arr[currentRow][currentColumn] = 2;

	// ������������ �� �� ������
	findExit(arr, rows, columns, currentRow - 1, currentColumn, path); // ������
	findExit(arr, rows, columns, currentRow + 1, currentColumn, path); // ������
	findExit(arr, rows, columns, currentRow, currentColumn - 1, path); // ������
	findExit(arr, rows, columns, currentRow, currentColumn + 1, path); // �������

	// �������� ������� �� ���� ���� �� ������� ��� (path)
	// �� ���� �� ����� ���� �� ������
	// ������ � �������������
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