#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long sum = 0;
        bool ans=true;
        for(long long i=n-1;i>0;i--){
            sum += a[i];
            long long s = ((n-i)*(n-i+1ll))/2ll;
            if(sum==s){
                ans=false;
                break;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}