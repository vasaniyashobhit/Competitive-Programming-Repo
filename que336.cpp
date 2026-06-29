#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long totalsum=0;
        for(auto it:a) totalsum += it;

        long long sum=0,maxsum=a[0];
        long long l=0,r=0;
        while(l<n && r<n){
            sum += a[r];
            if(sum<=0){
                r++;
                l=r;
                sum = 0;
                continue;
            }
            maxsum = max(sum,maxsum);
            r++;
        }

        //cout<<totalsum<<" "<<maxsum<<" ";
        
        if(maxsum>totalsum){
            cout<<"NO"<<endl;
        }
        else{
            bool k = true;
            sum=0;
            for(int i=0;i<n-1;i++){
                sum += a[i];
                if(sum<=0 || sum==totalsum) k=false;
            }
            if(k) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}