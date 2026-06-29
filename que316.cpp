#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,w; cin>>n>>w;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());

        multiset<long long> ms;
        long long ans=0;
        
        for(long long i=n-1;i>=0;i--){
            auto it = ms.lower_bound(a[i]);
            if(it==ms.end()){
                ans ++;
                ms.insert(w-a[i]);
            }
            else{
                long long newsize = *(it)-a[i];
                ms.erase(it);
                ms.insert(newsize);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}