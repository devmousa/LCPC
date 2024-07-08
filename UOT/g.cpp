#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    string s;
    cin >> s;

    // boolean value to see if we found the string or no
    bool found = false;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    // run a depth-first search (dfs) to check the adjacent cells and see if the value of a[i][j] is equal to s[curr]
    /** function paramters:
     * i: the current cell's row
     * j: the current cell's column
     * curr: the current index of the string S
     */
    function<void(int, int, int)> dfs = [&](int i, int j, int curr) -> void
    {
        // if curr value is equal to the string S size, then we found the string, change "found" value to true, then return and stop the function
        if (curr == s.size())
        {
            found = true;
            return;
        }

        // make sure that our cell is not out-of-bounds
        if (i >= n or i < 0 or j >= m or j < 0)
        {
            return;
        }

        // make sure that our cell is not visited before
        if (vis[i][j] == true)
        {
            return;
        }

        // if we found the string, we don't need to make any more search
        if (found)
        {
            return;
        }

        // mark the current cell as visited
        vis[i][j] = true;

        // see if the current cell is equal to the current index of the string S
        if (a[i][j] == s[curr])
        {
            dfs(i + 1, j, curr + 1);
            dfs(i - 1, j, curr + 1);
            dfs(i, j + 1, curr + 1);
            dfs(i, j - 1, curr + 1);
        }

        // mark the current cell as unvisited (we completed the current search, so we mark it as unvisited for the next search)
        vis[i][j] = false;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // search from the current cell (i, j)
            dfs(i, j, 0);

            // if we found the string, then exit the loops
            if (found == true)
            {
                j = m;
                i = n;
            }
        }
    }

    if (found == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}