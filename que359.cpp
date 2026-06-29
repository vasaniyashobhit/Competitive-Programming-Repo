#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int ans=0;
        int i=0,j=1;
        while(i<n && j<n){
            if(a[j]*2<=a[j-1]){
                i=j;
            }
            if(j-i+1>=k+1){
                ans++;
                //cout<<j<<" ";
            }
            j++;
        }
        //cout<<endl;
        cout<<ans<<endl;
    }

    return 0;
}