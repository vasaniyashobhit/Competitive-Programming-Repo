#include<bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
       
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main(){
    long long n,m; cin>>n>>m;
    long long mod = 1e9+7;
    long long twopow = power(2,m,mod);
    twopow--;
    long long ans = power(twopow,n,mod);
    cout<<ans<<endl;

    return 0;
}