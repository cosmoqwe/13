#include<iostream>
#include<ctime>
using namespace std;
void Delete(int** massiv, int col, int row)
{
	int col2 = col;
	int row2 = row;
	int** massiv2 = new int* [col2];
	for (int i = 0; i < col2; i++)
	{
		massiv2[i] = new int[row2];
	}
	int index;
	cout << "Input index:";
	cin >> index;
	cout << endl << endl;
	int q = 0;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (q!=index-1)
			{
				massiv2[i][j] = massiv[i][j];
			}
		}
		q++;
	}
	for (int i = 0; i < col2-1; i++)
	{
		for (int j = 0; j < row2; j++)
		{
			cout << massiv2[i][j] << " ";
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
	cout << "Input row:";
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
			cout << massiv[i][j] << " ";
		}
		cout << endl;
	}
	Delete(massiv, col, row);
}