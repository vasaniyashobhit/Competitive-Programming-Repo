#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<pair<int,int>> &dep, int currdep, vector<int> &subts, vector<int> &p){
    p[node] = parent;
    dep.push_back({currdep,node});
    subts[node] = 1;
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs(adj[node][i],node,adj,dep,currdep+1,subts,p);
        subts[node] += subts[adj[node][i]];
    }

    return;
}

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);

    vector<pair<int,int>> dep;
    vector<int> subts(n,0);
    vector<int> p(n);
    vector<int> deg(n);

    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++){
        deg[i] = adj[i].size();
    }

    dfs(0,-1,adj,dep,1,subts,p);

    sort(dep.begin(),dep.end());

    int sumleaf = 0,ptr=1,i=0;
    int minans = 1e8;
    for(int i=2;i<=dep[dep.size()-1].first;i++){
        int currans = sumleaf;
        while(ptr<dep.size() && dep[ptr].first==i){
            if(deg[dep[ptr].second]==1){
                int node = dep[ptr].second;
                while(deg[node]==1 && node!=0){
                    sumleaf++;
                    deg[p[node]]--;
                    node = p[node];
                }
            }
            else currans += subts[dep[ptr].second] - 1;
            ptr++;
        }
        minans = min(minans, currans);
        
    }
    
    cout<<minans<<endl;

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