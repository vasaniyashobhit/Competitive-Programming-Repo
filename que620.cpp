#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    vector<vector<int>> adj(n+2);
    for(int i=0;i<n;i++){
        adj[a[i]].push_back(i);
    }

    bool kk = true;
    for(int i=0;i<n;i++){
        if((adj[i].size())%k!=0) kk = false;
    }
    if(kk==false){
        cout<<0<<endl;
        return;
    }

    vector<int> lastind(n,1e8);
    for(int i=0;i<n;i++){
        sort(adj[i].begin(),adj[i].end());
        int m = adj[i].size();
        int cnt = m/k;
        for(int j=0;j<adj[i].size();j++){
            if(j+cnt>=m)  lastind[adj[i][j]] = 1e8;
            else lastind[adj[i][j]] = adj[i][j+cnt];  
        }
    }

    // for(auto it:lastind) cout<<it<<" ";
    // cout<<endl;

    // for(auto it: adj[2]) cout<<it<<" ";
    // cout<<endl;

    long long ans = 1;
    
    for(int i=n-2;i>=0;i--){
        int lastposs = min(lastind[i+1],lastind[i]);
        lastind[i] = lastposs;
        if(lastposs >= n) ans += n-i;
        else ans += lastposs - i;
    }
    // for(auto it:lastind) cout<<it<<" ";
    // cout<<endl;

    cout<<ans<<endl;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}