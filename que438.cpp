#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &cnt, int parent, int vertex, int &ans){
    int n = cnt.size();
    int m = adj[vertex].size();
    for(int j=0;j<m;j++){
        if(adj[vertex][j]==parent) continue;
        dfs(adj,cnt,vertex,adj[vertex][j],ans);
        cnt[vertex] += cnt[adj[vertex][j]];
    }
    if(cnt[vertex]%2==0 && vertex!=0){
        ans++;
        cnt[vertex] = 0;
    }

    return;
}

int main(){
    int n; cin>>n;
    vector<vector<int>> adj(n); 
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }

    vector<int> cnt(n,1);
    int ans=0;
    dfs(adj,cnt,-1,0,ans);
    cout<<ans<<endl;

    return 0;
}