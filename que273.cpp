#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> p(n);
        p[0] = a[0];
        for(int i=0;i<n;i++){
            p[i] = a[i]+p[i-1];
        }

        long long suml=0,ans=0,sum=0;
        for(long long i=1;i<=n;i++){
            suml = max(suml,i-(i*i)+sum);
            sum += a[i-1];
            ans = max(ans,(i*i)+i-sum+suml);
        }
        cout<<sum+ans<<endl;
    }

    return 0;
}