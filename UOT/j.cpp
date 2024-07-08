#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // make the array 1-indexed to make it simpler
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    // make a vector to see the visited values and take a decision according to it
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));

    // make the first and the last row visited (to make the operations simpler)
    for (int i = 0; i <= m + 1; i++)
    {
        vis[0][i] = true;
        vis[n + 1][i] = true;
    }

    // make the first and the last column visitd (to make the operations simpler)
    for (int i = 0; i <= n + 1; i++)
    {
        vis[i][0] = true;
        vis[i][m + 1] = true;
    }

    // start from the first cell (1, 1)
    int row = 1, col = 1;

    // store how many numbers you did output
    int curr = 0;

    /** directions:
     * 1: go right
     * 2: go down
     * 3: go left
     * 4: go up
     */
    int dir = 1;

    // loop until you output all the values
    while (curr != n * m)
    {
        // output the current cell
        cout << a[row][col] << ' ';

        // mark the current cell as visited
        vis[row][col] = true;

        // move according to the current direction
        // make sure that when you face an upcoming visited cell, you change the direction
        if (dir == 1)
        {
            if (vis[row][col + 1])
            {
                // change direction to down, and move down
                dir = 2;
                row++;
            }
            else
            {
                // go right
                col++;
            }
        }
        else if (dir == 2)
        {
            if (vis[row + 1][col])
            {
                // change direction to left, and move left
                dir = 3;
                col--;
            }
            else
            {
                // go down
                row++;
            }
        }
        else if (dir == 3)
        {
            if (vis[row][col - 1])
            {
                // change direction to up, and move up
                dir = 4;
                row--;
            }
            else
            {
                // go left
                col--;
            }
        }
        else if (dir == 4)
        {
            if (vis[row - 1][col])
            {
                // change direction to right, and move right
                dir = 1;
                col++;
            }
            else
            {
                // go up
                row--;
            }
        }

        // update the number of values we did output
        curr++;
    }
}