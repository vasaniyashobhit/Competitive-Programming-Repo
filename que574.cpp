#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent, vector<vector<int>> &adj,int &sum, string &s,vector<pair<int,int>> &counter){
    int cntb = 0;
    int cntw = 0;
    
    if(s[node]=='B') cntb++;
    else cntw++;

    for(int i:adj[node]){
        if(i==parent) continue;
        dfs(i,node,adj,sum,s,counter);
        cntw += counter[i].first;
        cntb += counter[i].second;
    }

    if(cntb==cntw) sum++;
    counter[node].first = cntw;
    counter[node].second = cntb;

    return;

}

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    
    for(int i=1;i<n;i++){
        int v; cin>>v;
        v--;
        adj[i].push_back(v);
        adj[v].push_back(i);
    }

    string s; cin>>s;

    int sum = 0;
    vector<pair<int,int>> counter(n,{0,0});
    dfs(0,-1,adj,sum,s,counter);
    cout<<sum<<endl;

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