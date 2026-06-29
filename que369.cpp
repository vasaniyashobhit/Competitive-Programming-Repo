#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> u(n);
        for(long long &it:u) cin>>it;
        vector<long long> s(n);
        for(long long &it:s) cin>>it;

        vector<vector<long long>> a(n+1);
        for(long long i=0;i<n;i++){
            a[u[i]].push_back(s[i]);
        }

        vector<vector<long long>> pref(n+1);
        for(long long i=1;i<=n;i++){
            if(a[i].size()==0) continue;

            sort(a[i].begin(),a[i].end(),greater<int>());
            long long nn = a[i].size();
            pref[i].push_back(a[i][0]);
            long long sum=pref[i][0];
            for(int j=1;j<nn;j++){
                pref[i].push_back(sum+a[i][j]);
                sum += a[i][j];
            }
        }

        // for(int i=1;i<=n;i++){
        //     for(auto it:pref[i]) cout<<it<<" ";
        //     cout<<endl;
        // }

        for(long long k=1;k<=n;k++){
            long long ans=0;
            for(long long i=1;i<=n;i++){
                long long nn = pref[i].size();
                if(nn==0 || k>nn) continue;
                ans += pref[i][nn-(nn%k)-1ll];
            }
            cout<<ans<<" ";
        }
        cout<<endl;


    }

    return 0;
}