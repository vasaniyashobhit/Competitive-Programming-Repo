#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        bool ans = false;
        for(int k=2;k<=1000;k++){
            long long sum = 1+k+(k*k);
            if(sum==n){
                //cout<<k<<" ";
                ans = true;
                break;
            }
            long long num = k*k;
            for(int i=3;i<=30;i++){
                num*=k;
                sum += num;
                if(sum==n){
                    ans=true;
                    break;
                }
                if(sum>1e6) break;
            }
            if(ans){
                //cout<<k<<" ";
                break;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}