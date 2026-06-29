#include<bits/stdc++.h>
using namespace std;

bool check(long long mid,long long n,long long m,long long k){
    long long req = mid-1;
    if(k-1>=req){
        if((req*2)-1>m) return false;
    }
    else{
        long long days = 2*(k-1)-1;
        long long ext = days+2-k;
        long long cr = mid-k;
        days += req-k+1;
        days += max(cr-ext,0ll);
        if(days>m) return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m,k; cin>>n>>m>>k;
        long long l=1,r=n;
        long long ans=1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(mid,n,m,k)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}