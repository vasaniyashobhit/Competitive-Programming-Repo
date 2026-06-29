#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

bool check(vector<long long> &a, long long sm, long long lr, long long num, vector<long long> &b){
    long long n = a.size();
    //cout<<sm<<" "<<lr<<endl;
    for(int i=0;i<n;i++){
        if(a[i]-num>=sm || a[i]+num<=lr) continue;
        else{
            if(a[i]!=b[i]) return false;
        }
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        if(is_sorted(a.begin(),a.end())){
            cout<<-1<<endl;
            continue;
        }

        vector<long long> b(n);
        for(int i=0;i<n;i++) b[i] = a[i];
        sort(b.begin(),b.end());

        long long sm = a[0], lr = a[0];
        for(int i=1;i<n;i++){
            if(a[i]>lr) lr = a[i];
            if(a[i]<sm) sm = a[i];
        }

        long long l = 1, r = lr+1;
        long long ans = -1;

        //cout<<check(a,sm,lr,3,b)<<endl;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(a,sm,lr,mid,b)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }

        cout<<ans<<endl;

    }

    return 0;
}