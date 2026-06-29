#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        vector<long long> a(n);
        vector<long long> c;
        for(long long &it:a)cin>>it;
        
        sort(a.begin(),a.end());
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                c.push_back(abs(a[i]-a[j]));
            }
        }
        sort(c.begin(),c.end());
        if(k==1){
            cout<<min(a[0],c[0])<<endl;
        }
        else{
            long long ans = c[0];
            long long nn = c.size();
            for(int i=0;i<nn;i++){
                auto it = lower_bound(a.begin(),a.end(),c[i]);
                long long ele1 = *(it);
                long long ele2 = *(--it);
                long long ans1 = min(abs(ele1-c[i]),abs(ele2-c[i]));
                ans = min(ans1,ans);
            }
            cout<<ans<<endl;
        }

    }

    return 0;
}