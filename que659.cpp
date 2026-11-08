#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(ll node, ll parent,vector<vector<ll>> &adj, vector<ll> &childs, vector<ll> &dep){
    
    if(parent != -1) dep[node] = dep[parent]+1;

    for(ll i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs(adj[node][i],node,adj,childs,dep);
        childs[node] += childs[adj[node][i]];
    }

    return;
}

void dfs2(ll node, ll parent,vector<vector<ll>> &adj,vector<ll> &ans, vector<ll> &childs, ll n){
    
    if(parent != -1){
        ans[node] = ans[parent] + n - 2*childs[node];
    }

    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs2(adj[node][i],node,adj,ans,childs,n);
    }

    return;
}



void solve() {
    ll n; cin>>n;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<n-1;i++){
        ll u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> childs(n,1);
    vector<ll> dep(n,0);
    dfs(0,-1,adj,childs,dep);

    ll sum = 0;
    for(auto it:dep) sum += it;
    vector<ll> ans(n,0);
    ans[0] = sum;

    dfs2(0,-1,adj,ans,childs,n);
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

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