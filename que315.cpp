#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<vector<long long>> a(n);
        for(int i=0;i<n;i++){
            int k; cin>>k;
            for(int j=0;j<k;j++){
                long long x; cin>>x;
                a[i].push_back(x);
            }
        }

        vector<pair<long long,long long>> b;
        for(long long i=0;i<n;i++){
            long long k = a[i].size();
            long long req=a[i][k-1]+1;
            for(int j=k-2;j>=0;j--){
                req--;
                req = max(req,a[i][j]+1);
            }
            b.push_back({req,k});
        }

        sort(b.begin(),b.end());
        long long ans = b[0].first;
        long long curr = ans+b[0].second;
        for(int i=1;i<n;i++){
            if(b[i].first>curr){
                ans += b[i].first-curr;
                curr = b[i].first;
                curr+=b[i].second;
            }
            else curr+=b[i].second;
        }

        cout<<ans<<endl;
    }

    return 0;
}