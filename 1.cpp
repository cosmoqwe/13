#include<iostream>
#include<ctime>
using namespace std;
void add(int** massiv, int col, int row)
{
	int index;
	cout << "Input index:";
	cin >> index;
	int col2=col+1, row2 = row;
	int** temp = new int*[col2];
	for (int i = 0; i < col2; i++)
	{
		temp[i] = new int[row];
	}
	cout << endl << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			temp[i][j] = massiv[i][j];
		}
	}
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i == index-1)
			{
				col++;
				temp[index][j] = 1 + rand() % 50;
			}
		}
	}
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}
void main()
{
	srand(time(NULL));
	int col, row;
	cout << "Input col:";
	cin >> col;
	cout << "Input row:"; 3;
	cin >> row;
	int** massiv = new int* [col];
	for (int i = 0; i < col; i++)
	{
		massiv[i] = new int[row];
	}
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			massiv[i][j] = 1 + rand() % 50;
		}
	}
	cout << "Do you want add col? Input 1 (yes) or 2 (no) :";
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		add(massiv, col, row);
	}
	else
	{
		cout << "Bye!";
		system("exit");
	}
}