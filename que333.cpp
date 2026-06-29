#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        long long divisor = 1;
        for(long long i=1;i*i<=n;i++){
            if(i>k) break;
            if(n%i==0){
                divisor = max(divisor,i);
                if((n/i)<=k) divisor = max(divisor,n/i);
            }
        }
        if(k>=n) divisor = n;
        cout<<n/divisor<<endl;
    }

    return 0;
}