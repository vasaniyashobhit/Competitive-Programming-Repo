#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        long long tot = 0;
        for(int i=1;i<n;i++){
            tot += abs(a[i]-a[i-1]);
        }

        long long larg = 0;
        for(int i=1;i<n-1;i++){
            long long bef = abs(a[i+1]-a[i])+abs(a[i]-a[i-1]);
            long long after = abs(a[i+1]-a[i-1]);
            larg = max(bef-after,larg);
        }
        larg = max(larg,abs(a[1]-a[0]));
        larg = max(abs(a[n-2]-a[n-1]),larg);
        cout<<tot-larg<<endl;
    }

    return 0;
}