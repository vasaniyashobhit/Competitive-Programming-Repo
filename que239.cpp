#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> &v, long long mid, long long x, long long a, long long y, long long b, long long k){
    long long n = v.size();
    long long sum=0;
    long long c = (a*b)/__gcd(a,b);
    long long z = x+y;
    if(y>x){
        swap(x,y);
        swap(a,b);
    }
    
    long long cnt = mid/c;
    long long xa = mid/a;
    long long yb = mid/b;
    xa -= cnt;
    yb -= cnt;
    int i=n-1;
    while(cnt>0){
        sum += (x+y)*(v[i]/100);
        cnt--;
        i--;
    }
    while(xa>0){
        sum += (x)*(v[i]/100);
        xa--;
        i--;
    }
    while(yb>0){
        sum += (y)*(v[i]/100);
        yb--;
        i--;
    }

    if(sum>=k) return true;
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> v(n);
        for(long long &it:v) cin>>it;
        long long x,a; cin>>x>>a;
        long long y,b; cin>>y>>b;
        long long k; cin>>k;
        sort(v.begin(),v.end());

        long long l=1,r=n;
        long long ans=-1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(v,mid,x,a,y,b,k)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        cout<<ans<<endl;
    }

    return 0;
}