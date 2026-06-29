#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long s,k,m; cin>>s>>k>>m;
        long long flips = m/k;
        long long extratime = m%k;

        if(flips%2==0 || s<=k){
            long long ans = s-extratime;
            ans = max(0ll,ans);
            cout<<ans<<endl;
        }
        else{
            long long ans = k-extratime;
            ans = max(0ll,ans);
            cout<<ans<<endl;
        }
    }

    return 0;
}