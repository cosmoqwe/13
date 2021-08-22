#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int** Create2D(int n, int m)
{
    int** mas = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        mas[i] = (int*)calloc(m, sizeof(int));
    }
    return mas;
}

void Delete2D(int** mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(mas[i]);
    }
    free(mas);
}

void InitArray(int** mas, int n, int m)
{
    for (int i = 0, k = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mas[i][j] = k;
            k++;
        }
        k = k + 1 - m;
    }
}

void ShowArray(int** mas, int n, int m)
{
    cout << "\n";
    int h = 5 * m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << mas[i][j] << "|";
        }
        cout << "\n";
        for (int i = 0; i < h; i++)
        {
            cout << '-';
        }
        cout << "\n";
    }
    cout << "\n";
}

void ShiftArray(int** mas, int n, int m, char direc, short shift)
{
    int** arr = Create2D(n, m);
    switch (direc)
    {
    case 'l':

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((shift + j - m) < 0)
                {
                    arr[i][j] = mas[i][j + shift];
                }
                else
                {
                    arr[i][j] = mas[i][shift + j - m];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
        break;
    case 'r':
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (m - shift + j > m - 1)
                {
                    arr[i][j] = mas[i][j - shift];
                }
                else
                {
                    arr[i][j] = mas[i][m - shift + j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
        break;
    case 'd':
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (n - shift + i > n - 1)
                {
                    arr[i][j] = mas[i - shift][j];
                }
                else
                {
                    arr[i][j] = mas[n - shift + i][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
        break;
    case 'u':
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (shift + i - n < 0)
                {
                    arr[i][j] = mas[i + shift][j];
                }
                else
                {
                    arr[i][j] = mas[shift + i - n][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mas[i][j] = arr[i][j];
            }
        }
        Delete2D(arr, n);
    default:
        break;
    }
}

int main()
{
    srand(time(0));
    int row, column;
    int** mas;
    cout << "Enter the number of lines => ";
    cin >> row;
    cout << "Enter the number of columns => ";
    cin >> column;
    mas = Create2D(row, column);
    InitArray(mas, row, column);
    cout << "\nOriginal array:\n";
    ShowArray(mas, row, column);
    cout << "Rows = " << row << "\nColumns = " << column << "\n\n";
    char ch;// верх, низ, лево, право
    short sh;// кол-во сдвигов
    cout << "Enter the number of shifts -> ";
    cin >> sh;
    cout << "Enter the direction of the shift:\n";
    cout << "l - to the left;\n"
        "r - to the right;\n"
        "u - up;\n"
        "d - down.\n";
    cin >> ch;
    ShiftArray(mas, row, column, ch, sh);
    ShowArray(mas, row, column);
    Delete2D(mas, row);
    return 0;
}