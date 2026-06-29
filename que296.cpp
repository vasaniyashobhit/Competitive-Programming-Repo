#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> c(n);
        for(long long &it:c) cin>>it;
        sort(c.begin(),c.end());

        if(c[0]!=1){
            cout<<"NO"<<endl;
            continue;
        }

        long long sum=c[0];
        bool k = true;
        for(int i=1;i<n;i++){
            if(c[i]>sum){
                k = false;
                break;
            }
            sum += c[i];
        }

        if(k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}