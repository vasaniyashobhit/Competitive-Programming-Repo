#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long m = 1e9+7;
        long long ans = n;
        ans = (ans*(4*n-1ll))%m;
        ans = (ans*(n+1ll))%m;
        ans = (ans*337ll)%m;
        ans %= m;
        cout<<ans<<endl;
    }

    return 0;
}