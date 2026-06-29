#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> pref(n);
        pref[0] = a[0];
        for(long long i=1;i<n;i++) pref[i] = a[i]+pref[i-1];

        long long ans=0;
        for(long long k=1;k<=n;k++){
            if(n%k==0){
                long long maxi = pref[k-1];
                long long mini = pref[k-1];
                for(long long j=2*k-1;j<n;j+=k){
                    long long sum = pref[j]-pref[j-k];
                    maxi = max(maxi,sum);
                    mini = min(mini,sum);
                }
                ans = max(ans,maxi-mini);
            }
        }
        cout<<ans<<endl;
        
    }

    return 0;
}