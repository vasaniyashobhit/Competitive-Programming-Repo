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

void dfs2(int node, int parent,int n, vector<int> &ans, vector<int> &diffarr){
    int sum = diffarr[node];

    for(int v:adj[node]){
        if(v==parent) continue;
        dfs2(v,node,n,ans,diffarr);
        sum += ans[v];
    }

    ans[node] = sum;

    return;
}


int main(){
    int n,q; cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 

    precompute(n,0); // n, root
    
    vector<int> diffarr(n,0);
    while(q--){
        int a,b; cin>>a>>b;
        a--;b--;
        int c = get_lca(a,b);
        diffarr[a]++;
        diffarr[b]++;
        
        if(c!=a && c!=b){
            diffarr[c]--;
            if(Par[c][0]!=-1) diffarr[Par[c][0]]--;
        }
        else{
            if(c==a){
                diffarr[a]--;
                if(Par[a][0]!=-1) diffarr[Par[a][0]]--;
            }
            else{
                diffarr[b]--;
                if(Par[b][0]!=-1) diffarr[Par[b][0]]--;
            }
        }
    }

    vector<int> ans(n,0);
    dfs2(0,-1,n,ans,diffarr);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;   
}