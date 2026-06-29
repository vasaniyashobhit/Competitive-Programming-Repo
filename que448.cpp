#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<int> a(11,0);
        a[0] = 1;
        a[1] = 3;
        a[2] = 6;
        a[3] = 10;
        a[4] = 15;
        a[5] = 21;
        a[6] = 28;
        a[7] = 36;
        a[8] = 45;
        a[9] = 55;
        long long ans=1;
        while(n>0){
            int i=n%10;
            ans *= a[i];
            n/=10;
        }
        cout<<ans<<endl;

    }

    return 0;
}