#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edg(n-1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        
        edg[i].first = u;
        edg[i].second = v;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    bool k = false;
    int v = -1;
    for(int i=0;i<n;i++){
        if(adj[i].size()>=3){
            v = i;
            k = true;
            break;
        }
    }

    if(k==false){
        for(int i=0;i<n-1;i++){
            cout<<i<<endl;
        }
        return;
    }

    map<pair<int,int>,int> mp;
    for(int i=0;i<3;i++){
        pair<int,int> edge = {v,adj[v][i]};
        mp[{v,adj[v][i]}] = i;
        mp[{adj[v][i],v}] = i;
    }

    int it = 3;
    for(int i=0;i<n-1;i++){
        if(mp.find(edg[i])!=mp.end()){
            cout<<mp[edg[i]]<<endl;
        }
        else{
            cout<<it<<endl;
            it++;
        }
    }

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