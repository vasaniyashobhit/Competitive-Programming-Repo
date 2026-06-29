#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long minlcm=n-1;
        pair<long long,long long> ans={1,n-1};
        for(long long i=2;i*i<=n;i++){
            if(n%i==0){
                long long a = i,b=n-a;
                long long a1 = n/i,b1=n-a1;

                long long lcm = (a*b)/__gcd(a,b);
                if(lcm<=minlcm){
                    minlcm = lcm;
                    ans.first = a;
                    ans.second = b;
                }

                lcm = (a1*b1)/__gcd(a1,b1);
                if(lcm<=minlcm){
                    minlcm = lcm;
                    ans.first = a1;
                    ans.second = b1;
                }

            }
        }
        cout<<ans.first<<" "<<ans.second<<endl;
    }

    return 0;
}