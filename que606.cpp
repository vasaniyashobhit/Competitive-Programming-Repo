#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent, vector<vector<int>> &adj, int &firstdm,vector<int> &dams){
    if(firstdm != -1) return;
    if(dams[node]==1){
        firstdm = node;
        return;
    }

    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs(adj[node][i],node,adj,firstdm,dams);
        if(firstdm != -1) break;
    }

    return;
}

void solve() {
    int n; cin>>n;

    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++){
        int x; cin>>x;
        x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    int m; cin>>m;
    vector<int> dams(n,0);
    for(int i=0;i<m;i++){
        int x; cin>>x;
        x--;
        dams[x] = 1;
    }

    

    if(dams[0]==1){
        
        cout<<m-1<<" ";
        for(int i=1;i<n;i++) if(dams[i]==1) cout<<i+1<<" ";
        cout<<endl;
    }
    else{
        
        cout<<m-1<<" ";
        int firstdm=-1;
        dfs(0,-1,adj,firstdm,dams);
        for(int i=0;i<n;i++) if(dams[i]==1 && i!=firstdm) cout<<i+1<<" ";
        cout<<endl;
    }
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