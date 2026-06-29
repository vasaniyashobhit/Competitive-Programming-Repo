#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> pref(n,0);
        if(a[0]<1) pref[0]=1;
        for(long long i=1;i<n;i++){
            pref[i] = pref[i-1];
            if(a[i]<=i) pref[i]++;
        }

        long long count=0;
        for(int i=1;i<n;i++){
            if(a[i]<=i && a[i]>1) count += pref[a[i]-2];
        }
        cout<<count<<endl;
    }

    return 0;
}