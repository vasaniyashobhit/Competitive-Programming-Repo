#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    
        long long n,m; cin>>n>>m;
        vector<long long> a(n);
        vector<long long> b(m);
        for(long long &it:a) cin>>it;
        for(long long &it:b) cin>>it;

        long long pre = 0;
        for(int i=1;i<n;i++){
            pre = __gcd(pre,abs(a[i]-a[0]));
        }
        //cout<<pre<<endl;

        for(int i=0;i<m;i++){
            long long ans = __gcd(a[0]+b[i],pre);
            cout<<ans<<" ";
        }
        cout<<endl;
    

    return 0;
}