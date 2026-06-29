#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(a[i]==1) cnt1++;
            if(a[i]==0) cnt0++;
        }

        if(cnt0==0) cout<<"NO"<<endl;
        else if(cnt0==1) cout<<"YES"<<endl;
        else{
            if(cnt1>=1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}