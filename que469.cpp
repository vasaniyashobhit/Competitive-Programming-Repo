#include <bits/stdc++.h>
using namespace std;

void bfs(int mainnode, vector<vector<int>> &adj, int n, vector<int> &ans)
{
    queue<int> q;
    vector<int> vis(n, 0);
    bool found = false;
    int dist = 0;
    q.push(mainnode);
    vis[mainnode] = 1;
    while (q.size())
    {
        if (found == true)
            break;
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
                    q.push(adj[node][j]);
                }
                else if (adj[node][j] == mainnode)
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
    }
    if (found)
        ans[mainnode] = dist;
    else
        ans[mainnode] = -1;
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 0)
                continue;
            else
                adj[i].push_back(j);
        }
    }

    vector<int> ans(n, 1e8);
    for (int i = 0; i < n; i++)
    {
        bfs(i, adj, n, ans);
    }
    for (auto it : ans)
    {
        if (it == -1)
            cout << "NO WAY" << endl;
        else
            cout << it << endl;
    }

    return 0;
}