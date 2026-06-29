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
    long long n; cin>>n;
    long long mod = 1e9+7;
    long long allcases = power(3,3*n,mod);
    long long badcases = power(7,n,mod);
    long long ans = (allcases%mod - badcases%mod + mod)%mod;
    cout<<ans<<endl;

    return 0;
}