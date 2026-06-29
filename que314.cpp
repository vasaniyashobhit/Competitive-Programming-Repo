#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> hash(32,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=30;j++){
                if(((a[i]>>j)&1)==1) hash[j]++;
            }
        }
        int g = hash[0];
        for(int i=1;i<=31;i++){
            g = __gcd(g,hash[i]);
        }
        for(int i=1;i<=g;i++){
            if(g%i==0) cout<<i<<" ";
        }
        if(g==0){
            for(int i=1;i<=n;i++) cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}