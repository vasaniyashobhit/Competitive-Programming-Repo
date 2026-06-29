#include<iostream>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
long long mul(long long a,long long b){
    return ((a%mod)*(b%mod))%mod;
}
long long add(long long a,long long b){
    return ((a%mod)+(b%mod))%mod;
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, mod - 2);
}

long long division(long long a, long long b) {
    a %= mod;
    long long inverse_b = modInverse(b);
    if (inverse_b == 0) {
        return -1;
    }
    return (a * inverse_b) % mod;
}

int main(){
    int t; cin>>t;
    long long mod = 1e9 + 7;
    while(t--){
        long long n,m; cin>>n>>m;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());
        
        map<long long,long long> mp;
        vector<long long> v;
        for(int i=0;i<n;i++){
            if(mp.find(a[i])==mp.end()) mp[a[i]]=1;
            else mp[a[i]]++;

            if(v.empty() || a[i]!=v.back()){
                v.push_back(a[i]);
            }
        }
        if(v.size()<m){
            cout<<0<<endl;
            continue;
        }

        long long count=0;
        long long k=1;
        for(long long i=0;i<m;i++){
            k = mul(k,mp[v[i]]);
        }
        if(v[m-1]-v[0]==m-1){
            count += k;
        }
        
        k = division(k,mp[v[0]]);
        for(long long i=1;i<=v.size()-m;i++){
            k = mul(k,mp[v[i+m-1]]);
            if(v[i+m-1]-v[i]==m-1){
                count = add(count,k);
            }
            k = division(k,mp[v[i]]);
        }
        cout<<count<<endl;
    }

    return 0;
}