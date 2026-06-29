#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long maxh = a[0];
        vector<long long> ans(n);
        ans[0] = a[0];

        long long sum = a[0];
        for(long long i=1;i<n;i++){
            sum += a[i];
            long long avg = sum/(i+1ll);
            maxh = min(maxh,avg);
            if(avg>maxh) avg = maxh;
            ans[i] = avg;
            // cout<<maxh<<"-"<<avg<<endl;
        }

        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}