#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int curr = 0;
    int row = 0, col = n / 2;
    // loop until we get all the values of the grid a
    while (curr != n * n)
    {
        curr++;
        a[row][col] = curr;
        vis[row][col] = true;

        // go the cell above the current cell, and go to the right of it. (assume the grid is infinitly using cycles, then you can use mod %)
        int new_row = (row - 1 + n) % n;
        int new_col = (col + 1) % n;

        // if the cell is visited before, then we will ignore it, and go the cell that under the current cell
        if (vis[new_row][new_col] == true)
        {
            new_row = (row + 1) % n;
            new_col = col;
        }

        row = new_row;
        col = new_col;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}