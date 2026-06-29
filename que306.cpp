#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> pe(n,0);
        vector<long long> po(n,0);
        map<long long,long long> mp;
        mp[a[0]]=1;
        mp[0] = 1;
        pe[0] = a[0];
        bool k = false;
        for(int i=1;i<n;i++){
            if(i%2==0){
                pe[i] = a[i]+pe[i-1];
                po[i] = po[i-1];
            }
            else{
                po[i] = a[i] + po[i-1];
                pe[i] = pe[i-1];
            }

            long long d = pe[i]-po[i];
            if(mp.find(d)!=mp.end()){
                k=true;
                break;
            }
            else mp[d]=1;
            //cout<<d<<" ";
        }
        if(k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}