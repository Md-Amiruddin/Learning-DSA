#include <bits/stdc++.h>
using namespace std;

bool isPlaceSafe(int **arr, int x, int y, int n)
{
    if (x < n && x < n && arr[x][y] == 1)
        return true;
    else
        return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **solarray)
{
    if (x == n - 1 && y == n - 1)
    {
        solarray[x][y] = 1;
        return true;
    }

    if (isPlaceSafe(arr, x, y, n))
    {
        solarray[x][y] = 1;

        if (ratInMaze(arr, x + 1, y, n, solarray))
            return true;
        if (ratInMaze(arr, x, y + 1, n, solarray))
            return true;

        solarray[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    int **solarray = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solarray[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            solarray[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, solarray))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solarray[i][j] << " ";
            }
            cout << endl;
        }
    }

    delete[] arr;
    delete[] solarray;
    arr=NULL;
    solarray=NULL;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1