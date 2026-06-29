#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long &it:a) cin>>it;
        for(long long &it:b) cin>>it;

        vector<long long> c(n);
        c[0] = __gcd(a[0],a[1]);
        c[n-1] = __gcd(a[n-1],a[n-2]);
        for(long long i=1;i<n-1;i++){
            long long g1 = __gcd(a[i],a[i-1]);
            long long g2 = __gcd(a[i],a[i+1]);
            c[i] = (g1*g2)/__gcd(g1,g2);
        }
        long long count=0;
        for(long long i=0;i<n;i++){
            if(c[i]!=a[i]) count++;
        }
        cout<<count<<endl;
        
    }

    return 0;
}