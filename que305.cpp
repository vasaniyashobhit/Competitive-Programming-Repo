#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        map<long long,long long> mp;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum += a[i];
            mp[sum] = i;
        }

        long long maxcnt=0;
        long long tot = 0;
        for(int i=n-1;i>=0;i--){
            tot += a[i];
            if(mp.find(tot)!=mp.end()){
                if(mp[tot]<i){
                    maxcnt = max(maxcnt,mp[tot]+1+(n-i));
                }
            }
        }
        cout<<maxcnt<<endl;
    }

    return 0;
}