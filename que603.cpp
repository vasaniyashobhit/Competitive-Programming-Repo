#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent, vector<vector<ll>> &adj, vector<ll> &suma, vector<ll> &sumb,vector<ll> &prefb, vector<ll> &ans, ll totalsuma,ll totalsumb){
    
    totalsuma += suma[node];
    totalsumb += sumb[node];
    if(parent != -1) prefb.push_back(totalsumb);
    
    if(parent!=-1){
        int count = upper_bound(prefb.begin(),prefb.end(),totalsuma) - prefb.begin();  
        ans[node] = count;
    }


    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs(adj[node][i],node,adj,suma,sumb,prefb,ans,totalsuma,totalsumb);
    }

    prefb.pop_back();
    return;
}

void solve() {
    int n; cin>>n;
    vector<vector<ll>> adj(n);
    vector<ll> suma(n,0);
    vector<ll> sumb(n,0);

    for(int j=1;j<n;j++){
        ll p,a,b; cin>>p>>a>>b;
        p--;
        adj[j].push_back(p);
        adj[p].push_back(j);

        suma[j] = a;
        sumb[j] = b;
    }

    vector<ll> ans(n,0);
    vector<ll> prefb;
    dfs(0,-1,adj,suma,sumb,prefb,ans, 0,0);
    for(int i=1;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;

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