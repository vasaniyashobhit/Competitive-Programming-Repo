#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        sort(a.begin(),a.end());
        long long ans = max(a[0],a[1]-a[0]);
        cout<<ans<<endl;
    }

    return 0;
}