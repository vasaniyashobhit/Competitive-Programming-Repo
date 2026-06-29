#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x; cin>>n>>x;
        vector<long long> a(n);
        for(auto &it:a) cin>>it;
        sort(a.begin(),a.end());

        vector<long long> pref(n);
        pref[0] = a[0];
        long long ind=0;
        for(long long i=1;i<n;i++){
            pref[i] = a[i]+pref[i-1];
            if(pref[i]<=x) ind=i;
        }
        
        long long days=0,sum=0;
        for(long long i=ind;i>=0;i--){
            long long s = pref[i] + days*(i+1);
            if(s<=x){
                long long day = ((x-s)/(i+1) + 1);
                sum += day*(i+1);
                days += day;
                //cout<<i+1<<"-"<<day*(i+1)<<" ";
            }
        }

        cout<<sum<<endl;

    }

    return 0;
}