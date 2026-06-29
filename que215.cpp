#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x,y; cin>>n>>x>>y;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        
        map<pair<long long,long long>,long long> mp; // {%y,%x},cnt
        for(long long i=0;i<n;i++){
            long long xx = a[i]%x;
            long long yy = a[i]%y;
            if(mp.find({yy,xx})==mp.end()){
                mp[{yy,xx}] = 1;
            }
            else mp[{yy,xx}]++;
        }

        long long count=0;
        for(auto it:mp){
            if(it.first.second>x/2) continue;
            if(2*(it.first.second)==x || it.first.second==0){
                count += ((it.second)*(it.second-1))/2ll;
            }
            else{
                if(mp.find({it.first.first,x-it.first.second})!=mp.end()){
                    count += mp[it.first]*mp[{it.first.first,x-it.first.second}];
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}