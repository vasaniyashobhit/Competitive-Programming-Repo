#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long sum=0;
        for(int i=0;i<n;i++) sum+=a[i];

        long long s=0;
        long long ans=-1;
        for(int i=0;i<n-1;i++){
            s+=a[i];
            long long gcd = __gcd(s,sum-s);
            ans = max(ans,gcd);
        }
        cout<<ans<<endl;

    }

    return 0;
}