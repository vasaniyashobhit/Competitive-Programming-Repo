#include<bits/stdc++.h>
using namespace std;

long double best = 1e9;
using ld = long double;

bool check(ld time, vector<ld> &x, vector<ld> &t, int &n){
    ld L = 0,R=1e8;
    for(int i=0;i<n;i++){
        ld l = x[i] - max(time-t[i],(ld)0);
        ld r = x[i] + max(time-t[i],(ld)0);

        L = max(L,l);
        R = min(R,r);
        if(L>R) return false;
    }
    best = (L+R)/2;
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ld> x(n);
        for(auto &it:x) cin>>it;
        vector<long double> t(n);
        for(auto &it:t) cin>>it;

        long double l=0,r=1e9;
        
        for(int i=0;i<=50;i++){
            long double mid = l + (r-l)/2;
            if(check(mid,x,t,n)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        cout<<setprecision(16)<<best<<endl;
    }
}