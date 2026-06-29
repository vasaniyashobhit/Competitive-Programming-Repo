#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long ans=0;
        for(int i=1;i<=n;i++){
            int k = a[i-1];
            while(k-i<=n){
                int j = k - i;
                if((j<=n) && (i<j) && a[i-1]*a[j-1]==i+j){
                    ans++;
                }
                k += a[i-1];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}