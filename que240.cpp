#include<iostream>
#include<vector>
using namespace std;

bool check(vector<long long> a,vector<long long> &b, long long mid){
    long long n = a.size();
    for(long long i=n-1;i>=2;i--){
        long long cangive = min(a[i]-mid, b[i]);
        a[i-1] += cangive/3;
        a[i-2] += 2*(cangive/3);
    }
    for(long long i=0;i<n;i++){
        if(a[i]<mid) return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long &it:a) cin>>it;
        for(int i=0;i<n;i++) b[i] = a[i];

        long long l=1,r=1e9;
        long long ans = -1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(a,b,mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<endl;

    }

    return 0;
}