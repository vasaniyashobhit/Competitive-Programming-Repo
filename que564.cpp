#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(vector<vector<int>> &adj, vector<int>&height, int node,int parent){
    
    int m = 0;

    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]==parent) continue;
        dfs(adj,height,adj[node][i],node);
        m = max(m,height[adj[node][i]]);
    }

    height[node] = m+1;
    return;

}

void solve() {
    int n; cin>>n;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    p[0] = -1;
    for(int i=1;i<n;i++){
        cin>>p[i];
        p[i]--;
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    
    vector<int> height(n);
    dfs(adj,height,0,-1);

    
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        if(i!=0){
            if(adj[i].size()>=3){
                vector<int> temp;
                for(auto it:adj[i]) temp.push_back(height[it]);
                sort(temp.begin(),temp.end());
                ans[i] = temp[temp.size()-3]+1;
            }
            else ans[i]=1;
        }
        else{
            vector<int> temp;
            for(auto it:adj[i]) temp.push_back(height[it]);
            sort(temp.begin(),temp.end());
            if(adj[0].size()>1) ans[i] = temp[temp.size()-2]+1;
            else ans[i] = 1;
        }
    }

    int fans = 0;
    for(auto it:ans){
        fans += it;
    }
    cout<<fans<<endl;
    
    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}