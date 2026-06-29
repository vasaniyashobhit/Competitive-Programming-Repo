#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long maxval=0;
        long long countmax=0,countsecmax=0;

        for(int i=0;i<n;i++) maxval = max(maxval,a[i]);

        for(int i=0;i<n;i++){
            if(a[i]==maxval) countmax++;
            if(a[i]==maxval-1) countsecmax++;
        }

        long long nfact=1,m=998244353,badcase=1;
        for(int i=n;i>=1;i--){
            nfact = ((nfact%m)*(i%m))%m;
            if(i!=(countsecmax+1)){
                badcase = ((badcase%m)*(i%m))%m;
            }
        }

        if(countmax>1){
            cout<<nfact<<endl;
        }
        else{
            if(countsecmax==0){
                cout<<0<<endl;
                continue;
            }
            long long ans = nfact;
            ans = ((nfact%m)-(badcase%m)+m)%m;
            cout<<ans<<endl;
        }
    }

    return 0;
}