#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool dfs(int node, int parent, int &root, vector<vector<int>> &adj, vector<int> &color){
    bool k = true;
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        if(node != root && color[node] != color[adj[node][i]]) return false;
        k = dfs(adj[node][i],node,root,adj,color);
        if(k==false) return false;
    }
    return true;
}

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges; 
    pair<int,int> roots;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u,v});
    }
    vector<int> color(n);
    for(int i=0;i<n;i++) cin>>color[i];

    for(int i=0;i<n-1;i++){
        if(color[edges[i].first] != color[edges[i].second]) roots = edges[i];
    }

    bool ans1 = dfs(roots.first,-1,roots.first,adj,color);
    bool ans2 = dfs(roots.second,-1,roots.second,adj,color);
    if(ans1==true){
        cout<<"YES"<<endl;
        cout<<roots.first+1<<endl;
    }
    else if(ans2==true){
        cout<<"YES"<<endl;
        cout<<roots.second+1<<endl;
    }
    else cout<<"NO"<<endl;
    
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}