#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj,int parent,int vertex,int &ans,int cnt,vector<int> &a,int m){
    if(a[vertex]==1) cnt++;
    else cnt = 0;

    if(cnt>m) return;
    if(adj[vertex].size()==1 && vertex!=0){
        ans++;
        return;
    }
    int n = adj[vertex].size();
    for(int i=0;i<n;i++){
        if(adj[vertex][i]==parent) continue;
        dfs(adj,vertex,adj[vertex][i],ans,cnt,a,m);
    }
    return;
}

int main(){
    int n,m; cin>>n>>m;
    vector<int> a(n);
    for(int &it:a) cin>>it;
    
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    dfs(adj,-1,0,ans,0,a,m);
    cout<<ans<<endl;


    return 0;
}