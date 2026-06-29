#include<bits/stdc++.h>
using namespace std;

vector<long long> dij(vector<vector<pair<int,int>>> &adj, int n, int source){
    vector<long long> dist(2*n+1,1e18);
    priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long,int>>> pq;
    dist[source] = 0;
    pq.push({0,source});
    while(!pq.empty()){
        pair<long long,int> curr = pq.top();
        pq.pop();
        int node = curr.second;
        long long nodedist = curr.first;

        if(nodedist > dist[node]) continue;

        for(pair<int,int> it : adj[node]){
            int v = it.first;
            int edge = it.second;
            if(dist[v]>edge+nodedist){
                dist[v] = edge+nodedist;
                pq.push({dist[v],v});
            }
        }

    }

    return dist;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(2*n+1);
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[a+n].push_back({b+n,c});
        adj[a].push_back({b+n,c/2});
    }

    vector<long long> distfs = dij(adj,n,0);
    
    cout<<distfs[2*n-1]<<"\n";

    return 0;
}