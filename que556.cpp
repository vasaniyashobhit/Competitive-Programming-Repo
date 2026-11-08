#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void bfs(vector<vector<int>> &adj,vector<int> &parent,int n){
    queue<int> q;
    vector<int> visited(n,0);
    visited[0] = 1;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<adj[v].size();i++){
            if(adj[v][i]==parent[v]) continue;
            visited[adj[v][i]]=1;
            q.push(adj[v][i]);
            parent[adj[v][i]] = v;
        }
    }

    return;
}

void dfs(int node,vector<vector<int>> &adj,set<int> ind, long long &ans, int cnt,vector<int> &parent){

    if(ind.find(node)==ind.end()) cnt++;
    else{
        ans += cnt;
    }

    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]!=parent[node]) dfs(adj[node][i],adj,ind,ans,cnt,parent);
    }

    return;
}

int main(){
    ll n,k; cin>>n>>k;
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        ll u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> parent(n);
    parent[0]=-1;
    bfs(adj,parent,n);

    vector<int> deg(n,0);
    for(int i=0;i<n;i++) deg[i] = adj[i].size();

    vector<int> powe(n,1);

    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        if(deg[i]==1) st.insert({0,i});
    }

    set<int> ind;
    for(int i=0;i<k;i++){
        pair<int,int> p = *st.begin();
        st.erase(st.begin());
        powe[parent[p.second]] += powe[p.second];
        deg[parent[p.second]]--;
        if(deg[parent[p.second]]==1) st.insert({powe[parent[p.second]],parent[p.second]});
        ind.insert(p.second);
    }

    long long ans=0;
    dfs(0,adj,ind,ans,0,parent);
    cout<<ans<<endl;

    return 0;
}