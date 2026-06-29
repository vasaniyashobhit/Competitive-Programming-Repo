#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        if(n%2==0){
            if(k%n==0) cout<<n<<endl;
            else cout<<k%n<<endl;
            continue;
        }
        long long ans = (k + ((k-1)/(n/2)))%n;
        if(ans==0) ans=n;
        cout<<ans<<endl;
    }

    return 0;
}