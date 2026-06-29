#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[a[i]]++;
        }
        sort(hash.begin(),hash.end());
        long long k = hash[n],ans=0;
        for (int i = n; i >= 0; i--)
        {
            if(k<=0) break;
            if(hash[i]>=k){
                ans += k;
                k--;
            }
            else{
                k = hash[i];
                ans += k;
                k--;
            }
            
        }
        cout<<ans<<endl;
        
    }

    return 0;
}