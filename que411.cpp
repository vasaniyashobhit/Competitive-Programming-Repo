#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> suff(n,0);
        map<int,int> mp;   // {x,index}
        mp[a[n-1]] = n-1;
        suff[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]^a[i];
            if(mp.find(suff[i])==mp.end()) mp[suff[i]] = i;
        }

        if(suff[0]==0){
            cout<<"YES"<<endl;
            continue;
        }
        
        int x=0;
        bool ans = false;
        for(int i=0;i<n;i++){
            x = x^a[i];
            if(suff[i+1]==0 && mp.find(x)!=mp.end() && mp[x]>i){
                ans = true;
                break;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}