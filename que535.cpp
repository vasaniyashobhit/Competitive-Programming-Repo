#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>> &adj, vector<int> &visited, int &open){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    bool k = false;
    while(!q.empty()){
       
        int vertex = q.front();
        q.pop();
        int m = adj[vertex].size();
        if(m==1) k = true;
        for(int i=0;i<m;i++){
            if(visited[adj[vertex][i]]==1) continue;
            q.push(adj[vertex][i]);
            visited[adj[vertex][i]] = 1;
        }
    }
    if(k==true) open++;

    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int x; cin>>x;
            x--;
            
            adj[i].push_back(x);
            adj[x].push_back(i);
        } 
        for(int i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end());
            adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
        }

        vector<int> visited(n,0);
        int comp = 0;
        int open = 0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                bfs(i,adj,visited,open);
                comp++;
            }
        }
        //cout<<open<<endl;
        int minround,maxround=comp;
        if(comp==open){
            minround = 1;
        }
        else{
            if(open>=2){
                minround = comp-open+1;
            }
            else minround = comp;
        }
        cout<<minround<<" "<<maxround<<endl;
    }
}