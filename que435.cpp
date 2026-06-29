#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &parent, vector<int> &level, int p, int vertex){
    int n = parent.size();
    int m = adj[vertex].size();
    if(vertex!=0) level[vertex] = level[p]+1;

    for(int i=0;i<m;i++){
        if(adj[vertex][i]==p) continue;
        parent[adj[vertex][i]] = vertex;
        dfs(adj,parent,level,vertex,adj[vertex][i]);
    }

    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> adj(n);
        for(int i=2;i<=n;i++){
            int u,v; cin>>u>>v;
            u--; v--;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        vector<int> parent(n,-1);
        vector<int> level(n,0);
        dfs(adj,parent,level,-1,0);

        int maxlvl = 0;
        for(int i=0;i<n;i++) maxlvl = max(maxlvl,level[i]);
        vector<vector<int>> lvl(maxlvl+1);
        for(int i=0;i<n;i++){
            lvl[level[i]].push_back(i);
        }

        int maxcount = 0;
        for(int i=0;i<=maxlvl;i++){
            int m = lvl[i].size();
            int count = m;
            int oneparent = parent[lvl[i][0]];
            bool k = false; 
            for(int j=0;j<m;j++){
                if(parent[lvl[i][j]]!=oneparent) k = true;
            }
            if(k==false) count++;
            maxcount = max(maxcount,count);
        }

        cout<<maxcount<<endl;
    }

    return 0;
}