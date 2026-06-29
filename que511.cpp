#include<bits/stdc++.h>
using namespace std;

vector<long long> dij(vector<vector<pair<int,int>>> &adj, int n, int source, vector<int> &parent){
    vector<long long> dist(n,1e18);
    priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long,int>>> pq;
    dist[source] = 0;
    pq.push({0,source});
    while(!pq.empty()){
        pair<long long,int> curr = pq.top();
        pq.pop();
        int node = curr.second;
        long long nodedist = curr.first;
        for(pair<int,int> it : adj[node]){
            int v = it.first;
            int edge = it.second;
            if(dist[v]>edge+nodedist){
                parent[v] = node;
                dist[v] = edge+nodedist;
                pq.push({dist[v],v});
            }
        }

    }

    return dist;
}

int main(){
    
        int n,m; cin>>n>>m;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            int a,b,w; cin>>a>>b>>w;
            a--;b--;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }

        vector<int> parent(n,-1);
        vector<long long> dist = dij(adj,n,0,parent);
        
        if(dist[n-1] == 1e18){
            cout << -1 << "\n";
            return 0;
        }

        vector<int> ans;
        for(int v = n-1; v != -1; v = parent[v]){
            ans.push_back(v);
        }

        reverse(ans.begin(), ans.end());

        for(int x : ans){
            cout << x + 1 << " ";
        }
        cout << "\n";
    
    
    

    return 0;
}