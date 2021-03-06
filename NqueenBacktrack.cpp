#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **a, int x, int y, int n)
{
    for (int row = 0; row < x; row++) //sweep the column up
    {
        if (a[row][y] == 1)
            return false;
    }

    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (a[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (a[row][col] == 1)
            return false;
        row--;
        col--;
    }

    return true;
}

bool nqueen(int **a, int x, int n)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(a, x, col, n))
        {
            a[x][col] = 1;

            if (nqueen(a, x + 1, n))
                return true;

            a[x][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    bool x = nqueen(a, 0, n);
    if (x)
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << a[row][col] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No Solution";
    }
    return 0;
}