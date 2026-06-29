#include<bits/stdc++.h>
using namespace std;

int main(){
    
    
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long sum=0;
        long long m=0;
        for(int i=0;i<n;i++){
            sum += a[i];
            m = max(m,a[i]);
        }
        
        if(sum%2==0 && m<=sum/2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    

    return 0;
}