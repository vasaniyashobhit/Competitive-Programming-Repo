#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> &b, long long mid, long long h){
    for(long long i=mid-1;i>=0;i-=2){
        h -= b[i];
    }
    if(h>=0) return true;
    else return false;
}

int main(){
    long long n,h; cin>>n>>h;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;

    long long l=1,r=n;
    long long ans=1;
    while(l<=r){
        long long mid = r - ((r-l)/2);
        vector<long long> b;
        for(long long i=0;i<mid;i++) b.push_back(a[i]);
        sort(b.begin(),b.end());
        if(check(b,mid,h)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout<<ans<<endl;

    return 0;
}