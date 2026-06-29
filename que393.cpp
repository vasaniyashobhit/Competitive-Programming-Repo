#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<set<int>> adj(n);
        for(int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            u--;v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        if(n==1){
            cout<<0<<endl;
            continue;
        }

        vector<int> degree(n);
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            degree[i] = adj[i].size();
            if(degree[i]==1) a.push_back(i);
        }

        long long cnt=0;
        while(k--){
            cnt += a.size();
            if(cnt>=n) break;
            for(int i=0;i<a.size();i++){
                int connected = *adj[a[i]].begin();
                degree[connected]--;
                adj[connected].erase(a[i]);
                if(degree[connected]==1) b.push_back(connected);
            }
            a.clear();
            for(int i=0;i<b.size();i++) a.push_back(b[i]);
            b.clear(); 
        }
        cout<<(n-cnt)<<endl;
        
    }

    return 0;
}