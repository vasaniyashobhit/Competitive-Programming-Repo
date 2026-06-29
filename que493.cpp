#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> heights(n);
    for (int &it : heights)
        cin >> it;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int s = adj[i].size();
        bool k = true;
        for (int j = 0; j < s; j++)
        {
            if (heights[adj[i][j]] >= heights[i])
                k = false;
        }
        if (k == true)
            count++;
    }

    cout << count << endl;

    return 0;
}