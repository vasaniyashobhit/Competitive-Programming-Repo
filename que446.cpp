#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &a,int k, int &ans){
    //cout<<k<<endl;
    int n = a.size();
    if(k==n){
        ans++;
        return;
    }
    int gcd = 0;
    for(int i=0;i<k;i++){
        int g = 0;
        for(int j=i+k;j<n;j+=k){
            g = __gcd(g,abs(a[j]-a[i]));
        }
        gcd = __gcd(gcd,g);
    }
    //cout<<k<<"-"<<gcd<<endl;

    if(gcd>=2 || gcd==0) ans++;
    return;

}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int ans=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                func(a,i,ans);
                if(i*i != n) func(a,n/i,ans);
            }
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
}