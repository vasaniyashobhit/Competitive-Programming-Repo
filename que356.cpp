#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m; cin>>n>>m;
        long long it=1,ans=1;
        while(n%10==0){
            ans*=10;
            n/=10;
        }
        while(n%2==0 && it*5<=m){
            n/=2;
            it*=5;
            ans*=10;
        }
        while(n%5==0 && it*2<=m){
            n/=5;
            it*=2;
            ans*=10;
        }
        ans*=n;
        while(it*10<=m){
            it*=10;
            ans*=10;
        }
        for(int i=9;i>=1;i--){
            if(it*i<=m){
                ans*=(i);
                break;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}