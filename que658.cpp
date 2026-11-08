#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent,vector<vector<int>> &adj, vector<int> &dist){
    if(parent!=-1) dist[node] = dist[parent]+1;
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs(adj[node][i],node,adj,dist);
    }

    return;
}

vector<int> givedist(int node, int parent,vector<vector<int>> &adj,int n){
    vector<int> d(n,0);
    dfs(node,-1,adj,d);
    return d;
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

    pair<int ,int> endpoint = {-1,-1};
    vector<int> distfrom0 = givedist(0,-1,adj,n);

    int m = 0;
    for(int i=0;i<n;i++){
        if(distfrom0[i]>m){
            m = distfrom0[i];
            endpoint.first = i;
        }
    }

    vector<int> distfromend1 = givedist(endpoint.first,-1,adj,n);

    m = 0;
    for(int i=0;i<n;i++){
        if(distfromend1[i]>m){
            m = distfromend1[i];
            endpoint.second = i;
        }
    }

    vector<int> distfromend2 = givedist(endpoint.second,-1,adj,n);

    for(int i=0;i<n;i++){
        cout<<max(distfromend1[i],distfromend2[i])<<" ";
    }
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