#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;
vector<vector<int>> adj(MAXN);                     // storing edges
vector<int> dep(MAXN,-1);                          // storing depth of each node
vector<vector<int>> Par(MAXN,vector<int>(LOG,-1));    // storing 2^ith parent of each node

// 1. dfs to compute initial depth and 1st ancestor (parent)
void dfs(int u, int parent){
    Par[u][0] = parent;

    for(int v:adj[u]){
        if(v==parent) continue;
        dep[v] = dep[u]+1;
        dfs(v,u);
    }
}

//2. calculating parent table (storing 2^ith parent) using dynamic programming
void precompute(int n, int root){
    dep[root] = 0;
    dfs(root,-1);

    for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            if(Par[i][j-1] != -1) Par[i][j] = Par[Par[i][j-1]][j-1];
        }
    }
}

// 3. get_LCA of node u and v
int get_lca(int u, int v){
    // to insure node u is always deeper than node v
    if(dep[u]<dep[v]) swap(u,v);

    // step 1. level the nodes
    int diff = dep[u]-dep[v];
    for(int i=0;i<LOG;i++){
        if((diff>>i)&1){
            u = Par[u][i];
        }
    }

    // if they were on same branch. that is one node is parent of other node then
    // after leveling, both node will become equal
    if(u==v) return u;

    // setp2. binary lifting  --> 64->32->32+16->32+8->32+8+4 
    for(int i=LOG-1;i>=0;i--){
        if(Par[u][i] != Par[v][i]){
            u = Par[u][i];
            v = Par[v][i];
        }
    }
    // after binary lifting u and v comes exactly one node below LCA
    return Par[u][0];

}

int kth_ancestor(int u, int k){
    for(int i=0;i<LOG && u!=-1;i++){
        if((k>>i)&1) u = Par[u][i];
    }
    return u;
}


int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<n;i++){
        int v; cin>>v;
        v--;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }

    precompute(n,0); // n, root
    
    while(q--){
        int a,b; cin>>a>>b;
        a--;b--;
        int ans = get_lca(a,b);
        cout<<(ans+1)<<endl;
    }

    return 0;
}