#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>> &adj, vector<int> &order){
    vector<int> visited(n,0);
    set<int> st;
    st.insert(0);
    visited[0] = 1;

    while(!st.empty()){
        int node = *st.begin();
        order.push_back(node);
        st.erase(node);
        for(int i=0;i<adj[node].size();i++){
            if(visited[adj[node][i]]==0){
                visited[adj[node][i]] = 1;
                st.insert(adj[node][i]);
            }
        }
    }

    return;
}

using ll = long long;

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--;
        v--;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> order;
    bfs(n,adj,order);
    for(auto it:order) cout<<it+1<<" ";
    cout<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}