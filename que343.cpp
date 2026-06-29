#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> x(n);
        for(int &it:x) cin>>it;
        if(n==1){
            cout<<0<<endl;
            continue;
        }

        vector<pair<int,int>> a(n,{0,0});
        a[0].second = x[1];
        a[n-1].first = x[n-2];
        for(int i=1;i<n-1;i++){
            int d = min(x[i+1]-x[i],x[i]-x[i-1]);
            a[i].first = x[i]-d;
            a[i].second = x[i]+d;
        }

        int ans=0;
        for(int i=0;i<n-1;i++){
            if(a[i].second>a[i+1].first) ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}