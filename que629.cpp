#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int &it:a) cin>>it;
    vector<int> b(n);
    for(int &it:b) cin>>it;

    int cnt = n-k;
    vector<int> hash(n+1,0);
    bool ans = true;
    for(int i=0;i<=cnt-1;i++){
        if(b[i]!=-1 && a[i]!=b[i]){
            ans = false;
            break;
        }
        hash[a[i]]=1;
    }
    for(int i=n-cnt;i<n;i++){
        if(b[i]!=-1 && a[i]!=b[i]){
            ans = false;
            break;
        }
        hash[a[i]]=1;
    }
    for(int i=cnt;i<n-cnt;i++){
        if(b[i]!=-1){
            if(hash[b[i]]==1) ans = false;
            hash[b[i]]=1;
        }
        
    }
    if(ans==false) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

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