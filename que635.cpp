#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(a[i])==mp.end())mp[a[i]]=1;
    }

    vector<int> ans(n+1,100);
    for(int i=1;i<=n;i++){
        if(mp.find(i)!=mp.end()) ans[i] = 1;
        for(int j=1;j*j<=i;j++){
            if(i%j!=0) continue;
            if(mp.find(j)!=mp.end() && ans[i/j]!=100){
                ans[i] = min(ans[i],1+ans[i/j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(ans[i]==100) cout<<-1<<" ";
        else cout<<ans[i]<<" ";
    }
    cout<<endl;
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