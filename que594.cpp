#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<pair<int,int>>> adj;
vector<int> getthere;
vector<int> ans;

void dfs(int node, int parent){
    for(int i=0;i<adj[node].size();i++){
        
        if(adj[node][i].first == parent) continue;
        
        dfs(adj[node][i].first,node);
        
        if(getthere[adj[node][i].first]==1) getthere[node] = 1;
        if(getthere[adj[node][i].first]==0 && adj[node][i].second==2){
            ans.push_back(adj[node][i].first+1);
            getthere[node] = 1;
        }
    }
    return;
}

void solve() {
    int n; cin>>n;
    adj.assign(n,vector<pair<int,int>>());
    getthere.assign(n,0);
    ans.assign(0,0);

    for(int i=0;i<n-1;i++){
        int u,v,t; cin>>u>>v>>t;
        u--;v--;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }

    dfs(0,-1);

    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) solve();

    return 0;
}