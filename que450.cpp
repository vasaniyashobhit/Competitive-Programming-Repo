#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int ans=-1;
        if(k==n){
            int it=1;
            for(int i=1;i<n;i+=2){
                if(a[i]!=it){
                    ans = it;
                    break;
                }
                it++;
            }
            if(ans==-1) cout<<it<<endl;
            else cout<<ans<<endl;
        }
        else{
            int cnt=0;
            for(int i=1;i<n;i++){
                if(a[i]==1) cnt++;
                else break;
            }
            if((n-k)>=cnt){
                ans = 1;
            }
            else{
                ans = 2;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}