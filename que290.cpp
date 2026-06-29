#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        map<long long,long long> mp;
        long long count=0;
        for(long long i=0;i<n;i++){
            if(mp.find(a[i]-i)==mp.end()){
                mp[a[i]-i]=1;
            }
            else{
                count += mp[a[i]-i];
                mp[a[i]-i]++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}