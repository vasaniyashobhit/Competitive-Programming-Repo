#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll helper(ll num){
    ll newa = 1;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            while((num%(i*i))==0) num = num/(i*i);
            if(num%i==0){
                newa *= i;
                num /= i;
            }
        }
    }
    if(num>1) newa *= num;
    return newa;
}

void solve() {
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;

    vector<ll> b(n);
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        b[i] = helper(a[i]);
        if(mp.find(b[i])==mp.end()) mp[b[i]]=1;
        else mp[b[i]]++;
    }

    ll count = 0;
    ll p = 1;
    for(int i=0;i<n;i++){
        p = (p/__gcd(p,b[i]))*(b[i]/__gcd(p,b[i]));
        if(mp.find(p)!=mp.end()){
            count += mp[p];
        }
    }
    cout<<count<<endl;
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