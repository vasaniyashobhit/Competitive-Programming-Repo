#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;
vector<vector<int>> adj(MAXN);                     
vector<int> dep(MAXN,-1);                         
vector<vector<int>> Par(MAXN,vector<int>(LOG,-1));    


void dfs(int u, int parent){
    Par[u][0] = parent;

    for(int v:adj[u]){
        if(v==parent) continue;
        dep[v] = dep[u]+1;
        dfs(v,u);
    }
}

void precompute(int n, int root){

    dfs(root,-1);

    for(int j=1;j<LOG;j++){
        for(int i=0;i<n;i++){
            if(Par[i][j-1]!=-1) Par[i][j] = Par[Par[i][j-1]][j-1];
        }
    }
}



int main(){
    int n,q; cin>>n>>q;
    for(int i=1;i<n;i++){
        int v; cin>>v;
        v--;
        adj[i].push_back(v);
        adj[v].push_back(i);
    } 

    precompute(n,0);

    while(q--){
        int x,k; cin>>x>>k;
        x--;
        for(int i=0;i<LOG;i++){
            if(x!=-1 && ((k>>i)&1)==1){
                x = Par[x][i];
            }
        }
        if(x!=-1)cout<<x+1<<endl;
        else cout<<-1<<endl;
    }

    
    return 0;
}