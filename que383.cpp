#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        
        if(n==1 && a[0]==1){
            cout<<1<<endl;
            continue;
        }
        
        sort(a.begin(),a.end());
        long long sum=0;
        for(long long it:a) sum += it;
        long long k = sum/2,ans=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]>=k){
                ans++;
                break;
            }
            else{
                ans++;
                k -= a[i];
            }
        }
        ans += sum/2;
        if(sum%2!=0) ans++;
        cout<<ans<<endl; 
    }

    return 0;
}