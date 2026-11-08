#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s; cin>>s;

    int y0=0,y1=0,x=0,m=0;
    for(int i=1;i<n;i++){
        if(adj[i].size()==1){
            if(s[i]=='1') y1++;
            else if(s[i]=='0') y0++;
            else x++;
        }
        else{
            if(s[i]=='?') m++;
        }
    }

    int ans = 0;
    if(s[0]=='0') ans += y1;
    else ans += y0;
    
    if(x%2==0) ans += x/2;
    else{
        if(s[0]=='?') m++;

        ans += m/2;
    }
    cout<<ans<<endl;
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