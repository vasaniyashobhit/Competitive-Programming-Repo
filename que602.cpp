#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dep1){
    if(parent != -1) dep1[node] = dep1[parent]+1;
    for(int i=0; i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs(adj[node][i],node,adj,dep1);
    }
    return;
}



void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dep1(n,1);
    dep1[0] = 1;
    dfs(0,-1,adj,dep1);
    pair<int,int> side1 = {0,-1};
    for(int i=0;i<n;i++){
        if(dep1[i]>side1.first){
            side1.first = dep1[i];
            side1.second = i;
        }
    }

    vector<int> ans(n,0);

    for(int i=0;i<n;i++){
        if(dep1[i]==side1.first) ans[i] = 1;
    }

    vector<int> dep2(n,1);
    dfs(side1.second,-1,adj,dep2);

    pair<int,int> side2 = {0,-1};
    for(int i=0;i<n;i++){
        if(dep2[i]>side2.first){
            side2.first = dep2[i];
            side2.second = i;
        }
    }

    for(int i=0;i<n;i++){
        if(dep2[i]==side2.first) ans[i] = 1;
    }

    for(int i=0;i<n;i++){
        if(ans[i]==0) cout<<side2.first-1<<endl;
        else cout<<side2.first<<endl;
    }

    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}