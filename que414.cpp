#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ava;
        for(int i=0;i<n;i++){
            int ver = adj[i].size()-1;
            for(int j=0;j<ver;j++) ava.push_back(a[i]);            
        }
        sort(ava.begin(),ava.end());
        long long sum = 0;
        for(int i=0;i<n;i++) sum += a[i];
        cout<<sum<<" ";
        int k=ava.size()-1;
        for(int i=1;i<=n-2;i++){
            if(k>=0){
                sum += ava[k];
                k--;
            }
            cout<<sum<<" "; 
        }
        cout<<endl;
    }

    return 0;
}