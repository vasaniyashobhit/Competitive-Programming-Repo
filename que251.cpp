#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m; cin>>n>>m;
    
    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    vector<long long> fact(n+1,0);
    fact[0] = 1;
    fact[1] = 1;
    
    for(int i=2;i<=n;i++){
        fact[i] = ((fact[i-1]%m)*(i%m))%m;
    }

    long long ans = 0;
    for(int d=1;d<=n;d++){
        long long sum = 0;
        sum = (n-d+1);
        sum = ((sum%m)*((n-d+1)%m))%m;
        sum = ((sum%m)*(fact[d]%m))%m;
        sum = ((sum%m)*(fact[n-d]%m))%m;
        ans = ((ans%m) + (sum%m))%m;
    }
    cout<<ans<<endl;

    return 0;
}