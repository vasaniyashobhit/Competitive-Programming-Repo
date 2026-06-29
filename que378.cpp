#include<bits/stdc++.h>
using namespace std;

int main(){
    
        long long n,m,k; cin>>n>>m>>k;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> gaps;
        for(int i=0;i<n-1;i++){
            gaps.push_back(a[i+1]-a[i]-1);
        }
        sort(gaps.begin(),gaps.end());
        long long ans = n;
        long long cnt = (n-1)-(k-1);
        for(int i=0;i<cnt;i++){
            ans += gaps[i];
        }
        cout<<ans<<endl;
    

    return 0;
}