#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    cin >> s >> p;

    int res = 0;
    // the condition i + p.size() - 1 < s.size() is to make sure that we don't take a substring out of the string S bounds
    for (int i = 0; i + p.size() - 1 < s.size(); i++)
    {
        string t = "";
        // get the value of the substring of the string P size that starts in the index i of the string S
        for (int j = i; j < i + p.size(); j++)
        {
            t.push_back(s[j]);
        }

        // if the substring is not the same as the string P, then continue
        if (t != p)
        {
            continue;
        }

        // otherwise, increment the result by one
        res++;
    }

    cout << res;
}