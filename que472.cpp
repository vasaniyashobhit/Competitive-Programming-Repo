#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &a, vector<vector<int>> &ans, int k)
{
    int n = a.size();
    queue<int> q;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            q.push(i);
            vis[i] = 1;
            ans[k][i] = 0;
        }
    }
    int dist = 0;
    while (q.size())
    {
        dist++;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            int node = q.front();
            q.pop();
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (vis[adj[node][j]] == 0)
                {
                    vis[adj[node][j]] = 1;
                    // ans[adj[node][j]].insert(dist);
                    ans[k][adj[node][j]] = dist;
                    q.push(adj[node][j]);
                }
            }
        }
    }

    return;
}

int main()
{
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> a(n);
    for (int &it : a)
        cin >> it;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // vector<multiset<int>> ans(n);
    vector<vector<int>> ans(k + 1, vector<int>(n));

    for (int i = 1; i <= k; i++)
    {
        bfs(adj, a, ans, i);
    }
    for (int j = 0; j < n; j++)
    {
        vector<int> ms;
        for (int i = 1; i <= k; i++)
        {
            ms.push_back(ans[i][j]);
        }
        sort(ms.begin(), ms.end());
        int sum = 0;
        for (int j = 0; j < s; j++)
        {
            sum += ms[j];
        }
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}