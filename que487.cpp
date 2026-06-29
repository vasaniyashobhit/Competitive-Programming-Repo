#include <bits/stdc++.h>
using namespace std;

void bfs(int count, vector<int> &visited, vector<vector<int>> &adj, int start)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        visited[node] = 1;
        int m = adj[node].size();
        for (int i = 0; i < m; i++)
        {
            if (visited[adj[node][i]] == 0)
            {
                visited[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
        q.pop();
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (string &it : v)
        cin >> it;

    vector<vector<int>> adj(26);
    vector<int> isthere(26, 0);
    for (int i = 0; i < n; i++)
    {
        int m = v[i].size();
        for (int j = 0; j < m - 1; j++)
        {
            adj[v[i][j] - 'a'].push_back(v[i][j + 1] - 'a');
            adj[v[i][j + 1] - 'a'].push_back(v[i][j] - 'a');

            isthere[v[i][j + 1] - 'a'] = 1;
            isthere[v[i][j] - 'a'] = 1;
        }
        if (m == 1)
            isthere[v[i][0] - 'a'] = 1;
    }

    vector<int> visited(26, 0);
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (visited[i] == 0 && isthere[i] == 1)
        {
            count++;
            bfs(count, visited, adj, i);
        }
    }
    cout << count << endl;

    return 0;
}