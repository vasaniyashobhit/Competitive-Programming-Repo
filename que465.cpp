#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(vector<vector<int>> &vis, int n, int m, int x, int y, int parentx, int parenty, char color, vector<string> &board, bool &ans)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (board[x][y] != color)
        return;
    if (vis[x][y] == 1)
    {
        ans = true;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if (nextx == parentx && nexty == parenty)
            continue;
        dfs(vis, n, m, nextx, nexty, x, y, color, board, ans);
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (string &it : board)
        cin >> it;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0)
            {
                dfs(vis, n, m, i, j, -1, -1, board[i][j], board, ans);
            }
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}