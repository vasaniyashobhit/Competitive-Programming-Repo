#include<bits/stdc++.h>
using namespace std;

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

long long modInverse(long long b, long long m) {
    return power(b, m - 2, m);
}

// Function to compute (a / b) % m
// Assumes m is a prime number
long long division(long long a, long long b, long long m) {
    a = (a % m + m) % m; // Handle negative 'a'
    long long b_inv = modInverse(b, m);
    return (a * b_inv) % m;
}

int main(){
    long long m = 1e9+7;
    vector<long long> fact(1000+1,0);
    fact[0] = 1;
    fact[1] = 1;
    
    for(int i=2;i<=1000;i++){
        fact[i] = ((fact[i-1]%m)*(i%m))%m;
    }
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        vector<long long>a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());
        long long ind = n-k;
        long long num = a[ind];
        auto it1 = upper_bound(a.begin(),a.end(),num);
        auto it2 = lower_bound(a.begin(),a.end(),num);
        long long ind1 = it1-a.begin()-1;
        long long ind2 = it2-a.begin();
        long long r = ind1-ind+1;
        long long nn = ind1-ind2+1;

        long long ans = fact[nn]%m;
        long long denominator = ((fact[r]%m)*(fact[nn-r]%m))%m;
        ans = division(ans,denominator,m);
        cout<<ans<<endl;

    }
    

    return 0;
}