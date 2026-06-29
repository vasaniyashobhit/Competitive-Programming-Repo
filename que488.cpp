#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> &colors, vector<vector<int>> &adj){
    queue <int> q;
    q.push(0);
    colors[0] = 1;
    while(!q.empty()){
        int node = q.front();
        int m = adj[node].size();
        for(int i=0;i<m;i++){
            if(colors[adj[node][i]]==0){
                if(colors[node]==1) colors[adj[node][i]] = 2;
                else colors[adj[node][i]] = 1;
                q.push(adj[node][i]);
            }
        }
        q.pop();
    }

    return;
}

int main(){
    long long n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<=n-1;i++){
        int a,b; cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> colors(n,0);
    bfs(colors,adj);

    
    long long redcolor = 0;
    for(int i=0;i<n;i++){
        if(colors[i]==2) redcolor++;
    }
    
    long long ans = (redcolor*(n-redcolor))-(n-1ll);
    cout<<ans<<endl;

    return 0;
}