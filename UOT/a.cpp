#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    char a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> pref2d(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pref2d[i][j] = pref2d[i - 1][j] + pref2d[i][j - 1] - pref2d[i - 1][j - 1] + (a[i][j] - '0');
        }
    }

    int res = 0;
    for (int end_row = n; end_row > 0; end_row--)
    {
        for (int end_col = m; end_col > 0; end_col--)
        {
            for (int start_row = end_row; start_row > 0; start_row--)
            {
                for (int start_col = end_col; start_col > 0; start_col--)
                {
                    // the sum of the rectangle that starts at (start_row, start_col) and ends at (end_row, end_col)
                    int sum = pref2d[end_row][end_col] - pref2d[end_row][start_col - 1] - pref2d[start_row - 1][end_col] + pref2d[start_row - 1][start_col - 1];
                    if (sum != 0)
                    {
                        break;
                    }

                    // find the maximum area
                    res = max(res, (end_row - start_row + 1) * (end_col - start_col + 1));
                }
            }
        }
    }

    cout << res;
}