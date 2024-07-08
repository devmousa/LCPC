#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();

    multiset<string> st;
    deque<string> dq;
    string vowels = "aeiouyAEIOUY";
    while (n--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;

        string t(s);
        st.insert(t);
        dq.push_back(t);
        if (dq.size() == 12)
        {
            st.erase(st.find(dq.front()));
            dq.pop_front();
        }

        int cnt = 0;
        int cnt2 = 0;
        bool f1 = false;
        bool f2 = false;
        while (ss >> word)
        {
            cnt2 = 0;
            for (char c : word)
            {
                if (vowels.find(c) == -1)
                {
                    cnt++;
                    cnt2++;
                }
                else
                {
                    cnt = 0;
                    cnt2 = 0;
                }

                if (cnt == 6)
                {
                    f1 = true;
                    break;
                }
                if (cnt2 == 5)
                {
                    f2 = true;
                }
            }
            if (f1)
            {
                break;
            }
        }

        if (f1)
        {
            cout << "n\n";
        }
        else if (f2)
        {
            if (st.count(t) > 3)
            {
                cout << "n\n";
            }
            else
            {
                cout << "y\n";
            }
        }
        else
        {
            if (st.count(t) > 2)
            {
                cout << "n\n";
            }
            else
            {
                cout << "y\n";
            }
        }
    }
}