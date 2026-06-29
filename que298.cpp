#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        int cnt=0;
        long long sum=0;
        long long sm=1e9+7;
        for(int i=0;i<n;i++){
            if(a[i]<0) cnt++;
            sum += abs(a[i]);
            sm = min(sm,abs(a[i]));
        }

        if(cnt%2==0) cout<<sum<<endl;
        else {
            sum = sum - 2*(sm);
            cout<<sum<<endl;
        }
    }

    return 0;
}