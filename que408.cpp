#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,a,b; cin>>n>>a>>b;
        vector<long long> x(n);
        for(long long &it:x) cin>>it;

        if(n==1){
            cout<<b*(x[0])<<endl;
            continue;
        }

        if(b>=a){
            long long sum = a*(x[n-2]);
            sum += b*x[0];
            for(long long i=1;i<n;i++){
                sum += b*(x[i]-x[i-1]);
            }
            cout<<sum<<endl;
        }
        else{
            vector<long long> suff(n,0);
            suff[n-1] = x[n-1];
            for(int i=n-2;i>=0;i--){
                suff[i] = suff[i+1] + x[i];
            }

            long long mincost=b*(suff[0]);
            long long sumstart = b*(x[0]);
            for(long long i=0;i<n-1;i++){
                long long c1 = b*(suff[i+1]-(n-i-1ll)*x[i]);
                long long c2 = a*(x[i]);
                if(i>=1) sumstart += b*(x[i]-x[i-1]);
                mincost = min(mincost,c1+c2+sumstart);
            }

            cout<<mincost<<endl;
        }
    }

    return 0;
}