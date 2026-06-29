#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m; cin>>n>>m;
        vector<long long> k(n);
        vector<long long> c(m);
        for(long long &it:k) cin>>it;
        for(long long &it:c) cin>>it;
        
        sort(k.begin(),k.end());
        long long cost=0;
        long long j=0;
        for(int i=n-1;i>=0;i--){
            if(j+1<k[i]){
                cost += c[j];
                j++;
            }
            else cost += c[k[i]-1];
        }
        cout<<cost<<endl;
    }

    return 0;
}