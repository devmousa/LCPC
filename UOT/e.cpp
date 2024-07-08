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

    set<int> st;
    vector<int> res;
    // using vector to push the values, and set to see if there are duplicates values or no;
    for (int i = 0; i < n; i++)
    {
        // see if the set have this number before or no (duplicated or no)
        if (st.find(a[i]) != st.end())
        {
            continue;
        }

        // if it is the first time to see this value
        // we will push it back to our result vector
        // and add it to the set to avoid adding duplicate values
        res.push_back(a[i]);
        st.insert(a[i]);
    }

    for (int el : res)
    {
        cout << el << ' ';
    }
}