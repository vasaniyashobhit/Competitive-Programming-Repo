#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 998244353;

vector<ll> fact(2*1e5+5,0);
void precompute(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=2*1e5;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    return;
}

void solve() {
    string s; cin>>s;
    int n = s.size();
    
    ll len = 1;
    ll ans1 = 0;
    ll ans2 = 1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            len++;
        }
        else{
            ans1 += len-1;
            ans2 = (ans2*len)%mod;
            len = 1;
        }
    }
    ans1 += len-1;
    ans2 = (ans2*len)%mod;
    ans2 = ((ans2%mod)*(fact[ans1]%mod))%mod;
    cout<<ans1<<" "<<ans2<<endl;

    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    precompute();
    while (t--) solve();

    return 0;
}