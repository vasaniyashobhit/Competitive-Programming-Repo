#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char di[4] = {'U', 'D', 'L', 'R'};

void bfs(int indx, int indy, vector<string> &a, vector<vector<int>> &vis, bool &ans1, int &ans2, int n, int m, vector<vector<char>> &parent)
{
    queue<pair<int, int>> q;
    bool found = false;
    q.push({indx, indy});
    int dist = 1;
    while (!q.empty())
    {
        dist++;
        if (found == true)
        {
            break;
        }
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int newx = p.first + dx[k];
                int newy = p.second + dy[k];
                if (newx < 0 || newx >= n || newy < 0 || newy >= m)
                    continue;
                if (vis[newx][newy] == 0 && (a[newx][newy] == '.' || a[newx][newy] == 'B'))
                {
                    if (a[newx][newy] == 'B')
                        found = true;
                    q.push({newx, newy});
                    parent[newx][newy] = di[k];
                    vis[newx][newy] = 1;
                }
            }
        }
    }
    ans1 = found;
    ans2 = dist;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }

    int indx = -1, indy = -1;
    int indbx = -1, indby = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
            {
                indx = i;
                indy = j;
            }
            if (a[i][j] == 'B')
            {
                indbx = i;
                indby = j;
            }
        }
    }
    // cout<<"hello"<<endl;
    bool ans1 = false;
    int ans2 = -1;
    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<char>> parent(n, vector<char>(m));
    bfs(indx, indy, a, vis, ans1, ans2, n, m, parent);
    if (ans1)
    {
        cout << "YES" << endl;
        cout << ans2 - 2 << endl;
        string ans = "";
        int x = indbx;
        int y = indby;
        for (int i = ans2 - 2; i >= 0; i--)
        {
            ans += parent[x][y];
            char ch = parent[x][y];
            if (ch == 'U')
            {
                x -= 1;
            }
            else if (ch == 'D')
            {
                x += 1;
            }
            else if (ch == 'R')
            {
                y += 1;
            }
            else
                y -= 1;
        }
        // cout<<ans<<endl;
        for (int i = ans.size() - 2; i >= 0; i--)
        {
            char it = ans[i];
            if (it == 'U')
                cout << "D";
            else if (it == 'D')
                cout << "U";
            else if (it == 'L')
                cout << "R";
            else
                cout << "L";
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}