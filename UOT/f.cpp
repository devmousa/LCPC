#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // solving this problem using dynamic programming (dp)
    // the state of this dp is as follows:
    // dp[i] = 1 for each 0 <= i < n
    // two nested for loops, i from 0 to n-1, j from 0 to i-1
    // if this condition (a[i] > a[j]) is false, we will continue
    // otherwise, the state will be like this:
    // dp[i] = max(dp[i], dp[j] + 1);
    // continue with my subsequence, or take previous subsequence and add one to it (take the maximum)
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] <= a[j])
            {
                continue;
            }

            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    // the result is the maximum value in the dp array
    int mx = 1;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, dp[i]);
    }

    cout << mx;
}
