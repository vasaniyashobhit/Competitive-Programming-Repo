#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> &a, long long hour, vector<long long> &hash, long long n){
    long long workr = 0;
    long long rem = 0;
    for(int i=1;i<=n;i++){
        if(hash[i]>=hour){
            rem += hash[i]-hour;
        }
        else{
            workr += (hour-hash[i])/2;
        }
    }
    if(rem>0 && rem>workr) return false;
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m; cin>>n>>m;
        vector<long long> a(m,0);
        for(auto &it:a) cin>>it;

        vector<long long> hash(n+1,0);
        for(int i=0;i<m;i++){
            hash[a[i]]++;
        }

        long long l=1,r=2*m;
        long long ans=-1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(a,mid,hash,n)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        cout<<ans<<endl;
    }

    return 0;
}