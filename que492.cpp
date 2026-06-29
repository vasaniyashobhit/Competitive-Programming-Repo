#include<bits/stdc++.h>
using namespace std;

void bfs(long long start,long long count,vector<vector<long long>> &adj, vector<long long> &visited){
    visited[start] = count;
    queue<long long> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        int m = adj[node].size();
        for(int i=0;i<m;i++){
            if(visited[adj[node][i]]==0){
                visited[adj[node][i]] = count;
                q.push(adj[node][i]);
            }
        }
        q.pop();
    }
}

int main(){
    long long n,m,k; cin>>n>>m>>k;
    
    vector<long long> capitals(k);
    for(int i=0;i<k;i++){
        cin>>capitals[i];
        capitals[i]--;
    }

    vector<vector<long long>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> visited(n);
    long long count = 0;
    for(int i=0;i<k;i++){
        count++;
        bfs(capitals[i],count,adj,visited);
    }

    long long freenodes = 0;
    for(int i=0;i<n;i++) if(visited[i]==0) freenodes++;

    vector<long long> groups(10000,0);
    for(int i=0;i<n;i++) if(visited[i]!=0) groups[visited[i]]++;

    long long lr = 0;
    for(int i=0;i<10000;i++) lr = max(groups[i],lr);
    for(int i=0;i<10000;i++){
        if(groups[i]==lr){
            groups[i] += freenodes;
            break;
        }
    } 

    // cout<<freenodes<<endl;

    // for(auto it:visited) cout<<it<<" ";
    // cout<<endl;

    // for(int i=0;i<5;i++) cout<<groups[i]<<" ";
    // cout<<endl;

    long long maxedges = 0;
    for(int i=1;i<10000;i++){
        if(groups[i]>1){
            maxedges += (groups[i]*(groups[i]-1))/2;
        }
    }

    cout<<(maxedges-m)<<endl;

}