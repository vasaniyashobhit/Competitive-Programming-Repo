#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<long long>> &adj,vector<long long> &sub,long long vertex, long long parent){
    if(adj[vertex].size()==1 && vertex != 0){
        sub[vertex] = 0;
        return; 
    }

    long long n = adj[vertex].size();
    sub[vertex] += adj[vertex].size() - 1; 
    for(int i=0;i<n;i++){
        if(adj[vertex][i]==parent) continue;
        dfs(adj,sub,adj[vertex][i],vertex);
        sub[vertex] += sub[adj[vertex][i]];
    }

    return;
}

int main(){
    int n; cin>>n;
    vector<vector<long long>> adj(n);
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        adj[i-1].push_back(x-1);
        adj[x-1].push_back(i-1);
    }

    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    vector<long long> sub(n,0);
    sub[0] = 1;
    dfs(adj,sub,0,-1);
    for(int i=0;i<n;i++) cout<<sub[i]<<" ";
    cout<<endl;

    return 0;
}