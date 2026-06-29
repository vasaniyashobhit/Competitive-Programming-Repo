#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        vector<vector<long long>> a(n,vector<long long>(n));
        for(auto &it:a){
            for(auto &itt:it) cin>>itt;
        }

        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
       

        long long count = 0;
        for(long long i=0;i<n/2;i++){
            for(long long j=0;j<n;j++){
                if(a[i][j]!=a[n-i-1][n-j-1]) count++;
            }
        }
        
        if(n%2!=0){
            for(long long j=0;j<n/2;j++){
                if(a[n/2][j]!=a[n/2][n-j-1]) count++;
            }
        }

        if(count>k){
            cout<<"NO"<<endl;
        }
        else{
            if((n%2==0) && ((k-count)%2!=0)) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }

    return 0;
}