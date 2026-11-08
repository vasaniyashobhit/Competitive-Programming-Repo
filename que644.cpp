#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(ll node, ll parent, vector<vector<pair<ll,ll>>> &adj, map<ll,ll> &mp, ll xorr){
    for(ll i=0; i<adj[node].size(); i++){
        if(adj[node][i].first==parent) continue;
        ll newxor = xorr^adj[node][i].second;
        mp[newxor] = adj[node][i].first;
        dfs(adj[node][i].first,node,adj,mp,newxor);
    }
    return;
}

void dfs2(ll node, ll parent, vector<vector<pair<ll,ll>>> &adj, map<ll,ll> &mp, ll xorr,ll a, ll b,bool &ans){
    if(node==b && xorr==0){
        ans = true;
        return;
    }
    else if(mp.find(xorr)!=mp.end() && node!=b){
        ans = true;
        return;
    }

    for(ll i=0; i<adj[node].size(); i++){
        if(adj[node][i].first==parent || adj[node][i].first==b) continue;
        ll newxor = xorr^adj[node][i].second;
        dfs2(adj[node][i].first,node,adj,mp,newxor,a,b,ans);
    }
    return;
}

void solve() {
    ll n,a,b; cin>>n>>a>>b;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<n-1;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    map<ll,ll> mp; // xor from (b to node), node 
    dfs(b,-1,adj,mp,0);

    bool ans = false;
    dfs2(a,-1,adj,mp,0,a,b,ans);

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}