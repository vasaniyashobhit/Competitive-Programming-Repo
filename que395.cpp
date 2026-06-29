#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long &it:a) cin>>it;
        for(long long &it:b) cin>>it;

        if(n==1){
            cout<<min(a[0],b[0])<<endl;
            continue;
        }

        vector<long long> prefb(n,0);
        prefb[0] = b[0];
        for(long long i=1;i<n;i++) prefb[i] += prefb[i-1]+b[i];

        vector<long long> prefa(n,0);
        vector<long long> ans(n,0);
        vector<long long> ext(n,0);

        for(long long i=0;i<n;i++){
            long long num = (i>0) ? a[i]+prefb[i-1]:a[i]; 
            long long l = i;
            auto it = (upper_bound(prefb.begin(),prefb.end(),num));
            it--;
            long long r = (it==prefb.end()) ? n : it-prefb.begin();
            //cout<<l<<"-"<<r<<" ";
            if(r<l || b[i]>=a[i]) ext[l] += a[i];
            else{
                prefa[i]++;
                if(r<n-1){
                    prefa[r+1]--;
                    ext[r+1] += num-prefb[r];
                }

            }
        }
        for(long long i=1;i<n;i++){
            prefa[i] +=prefa[i-1];
        }

        for(long long i=0;i<n;i++){
            ans[i] = (prefa[i]*b[i])+ext[i];
        }

        for(long long i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}