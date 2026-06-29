#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long maxsec = 0,ext=0;
        for(int i=1;i<n;i++){
            if(a[i]>=a[i-1]) continue;
            long long diff = a[i-1] - a[i];
            long long sec=0;
            for(long long j=0;j<=32;j++){
                if((diff>>j)&1==1) sec = j;
            }
            a[i] = a[i-1];
            maxsec = max(maxsec,sec+1);
        }
        cout<<maxsec<<endl;
    }

    return 0;
}