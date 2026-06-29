#include<bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int source){
    vector<long long> dist(2*n+5,1e18);
    priority_queue<pair<int,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    // pq stores {distance, node} in increasing order

    dist[source] = 0;
    pq.push({0,source});

    while(!pq.empty()){
        pair<long long,int > currnode = pq.top();
        pq.pop();
        long long nodedist = currnode.first;
        long long node = currnode.second;

        for(pair<int,int> &i: adj[node]){
            int v = i.first;
            int weight = i.second;
            if(dist[v]>dist[node] + weight){
                dist[v] = dist[node] + weight;
                pq.push({dist[v],v});
            }
        }
    }

    return dist;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,h; cin>>n>>m>>h;  // nodes, edges

        vector<int> horses(h);
        for(auto &it: horses) cin>>it;

        vector<vector<pair<int,int>>> adj(2*n+5);   // stores {connected node, index-node distance}
        for(int i=0;i<m;i++){
            int u,v,w; cin>>u>>v>>w;
            u--;v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

            u+=n;v+=n;
            adj[u].push_back({v,w/2});
            adj[v].push_back({u,w/2});
            
        }

        for(int i=0;i<h;i++) adj[horses[i]-1].push_back({horses[i]-1+n,0}); // // i->i+n;
        
        for(int i=0;i<n;i++) adj[i+n].push_back({i,0});
        
        vector<long long> distr = dijkstra(n,adj,0);
        vector<long long> distm = dijkstra(n,adj,n-1);

        long long mintime = 1e18;
        for(int i=0;i<2*n;i++){
            long long time = max(distr[i],distm[i]);
            mintime = min(time,mintime);
        }

        if(mintime>=1e18) mintime = -1;

        cout<<mintime<<endl;
    }
}