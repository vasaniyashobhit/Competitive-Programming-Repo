#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> grid;

void bfs(int n, int m, pair<int,int> start, pair<int,int> end){
    vector<vector<vector<int>>> visited(n,vector<vector<int>>(m,vector<int>(16,-1)));

    int steps = 0;
    visited[start.first][start.second][0] = 1;
    queue<pair<pair<int,int>,int>> q;
    q.push({{start.first,start.second},0});

    while(!q.empty()){
        pair<pair<int,int>,int> node = q.front();
        q.pop();
        steps++;
        
        //up

        //down

        //left

        //right
    }
}

void solve() {
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        grid.push_back(s);
    }

    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='S'){
                start.first = i;
                start.second = j;
            }
            if(grid[i][j]=='T'){
                end.first = i;
                end.second = j;
            }
        }
    }

    // bfs(n,m,s,e);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}