#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // initialize the graph
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, p;
        cin >> u >> v >> p;

        // direct graph, add a route from the city u to the city v with cost p
        adj[u].push_back({v, p});
    }

    int s, d;
    cin >> s >> d;

    vector<pair<vector<int>, int>> res;
    // run a depth-first search (dfs) to find all the routes from s to d, and add them to the result vector
    /** function paramters:
     * u: the current city
     * curr: vector that have the route from the city s to the current city
     * sum: the sum of the route from the city s to the current city
     */
    function<void(int, vector<int>, int)> dfs = [&](int u, vector<int> curr, int sum) -> void
    {
        // if the current city is d, then we found a route from the city s to the city d
        // add this route to the result vector
        if (u == d)
        {
            res.push_back({curr, sum});
            return;
        }

        // go for the cities that have a route from the city u
        for (auto [to, cost] : adj[u])
        {
            // add the city "to" to "curr" vector
            curr.push_back(to);

            // run a dfs with current sum + the cost to go to the city "to"
            dfs(to, curr, sum + cost);

            // remove the city "to" from the "curr" vector to start a new route (if there are any)
            curr.pop_back();
        }
    };

    // run the dfs from the city s and with cost 0
    dfs(s, vector<int>{s}, 0);

    // if the size of the result vector is 0, then there is no route from the city s to the city d, output -1 and stop the program
    if (res.size() == 0)
    {
        cout << -1;
        return 0;
    }

    // sort the result vector according to the cost of the routes
    sort(res.begin(), res.end(), [&](auto l, auto r)
    {
        // first is the cities in the route
        // second is the cost of this route
        return l.second < r.second; 
    });

    // output the result as mentioned in the problem
    for (int i = 0; i < res.size(); i++)
    {
        vector<int> route = res[i].first;
        int cost = res[i].second;
        for (int j = 0; j < route.size(); j++)
        {
            cout << route[j];

            // to make sure that we don't print an extra arrow "->" after the last city "d"
            if (j + 1 != route.size())
            {
                cout << " -> ";
            }
        }
        cout << ", ";
        cout << cost;
        cout << '\n';
    }
}