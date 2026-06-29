#include<iostream>
#include<vector>
using namespace std;

bool check(long long n, vector<long long> s, long long c, long long mid){
    bool k = true;
    long long area=0;
    for(int i=0;i<n;i++){
        area += (s[i]+2*mid)*(s[i]+2*mid);
        if(area>c){
            k = false;
            break;
        }
    }
    return k;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n,c; cin>>n>>c;
        vector<long long> s(n);
        for(long long &it:s) cin>>it;

        long long l=1,r=1e9;
        long long ans=1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(n,s,c,mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}