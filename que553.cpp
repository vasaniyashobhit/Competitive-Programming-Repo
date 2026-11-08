#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod =  998244353;

vector<long long> fact;
vector<long long> invFact;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}


long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

void precompute(ll maxN, long long mod) {
    fact.resize(maxN + 1);
    invFact.resize(maxN + 1);
    
    fact[0] = 1;
    invFact[0] = 1;
    
    for (int i = 1; i <= maxN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
      
    invFact[maxN] = modInverse(fact[maxN], mod);
     
    for (int i = maxN - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

ll nCrMod(int n, int r, ll mod) {
    if (r < 0 || r > n) return 0;
    
    ll num = fact[n];
    ll den = (invFact[r] * invFact[n - r]) % mod;
    
    return (num * den) % mod;
}


int main(){
    int t; cin>>t;
    precompute(2*1e6, mod);
    
    while(t--){
        int n; cin>>n;
        vector<ll> a(n);
        for(ll &it:a) cin>>it;

        if(n==1){
            cout<<0<<endl;
            continue;
        }

        vector<ll> b(32,0);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<=31;j++){
                if(((a[i]>>j)&1)==1) b[j]++;
            }
        }

        ll ans = 1;

        for(ll i=31;i>=0;i--){
            if(b[i]%2!=0){
                ll x = nCrMod(b[i],b[i]-1,mod);
                ans = (ans*x)%mod;
                break;
            }
            
        }
        cout<<ans<<endl;


    }


    return 0;
}