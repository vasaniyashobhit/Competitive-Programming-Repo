#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> hash(1001,-1);
        for(int i=0;i<n;i++){
            hash[a[i]]=i;
        }

        int ans=-1;
        for(int i=1;i<=1000;i++){
            if(hash[i]==-1) continue;
            for(int j=1;j<=1000;j++){
                if(hash[j]==-1) continue;
                if(__gcd(i,j)==1) ans = max(ans,hash[i]+hash[j]);
            }
        }
        if(ans==-1) cout<<-1<<endl;
        else cout<<ans+2<<endl;
    }

    return 0;
}