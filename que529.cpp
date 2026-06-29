#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> p;
        long long x = a[0];
        while(x!=1){
            p.push_back(x);
            if(x%2==0) x/=2;
            else x++;
        }
        p.push_back(1);
        p.push_back(2);

        long long minans=1e18;
        for(long long i=0;i<p.size();i++){
            long long req = p[i];
            long long op = 0;
            bool k = true;
            for(long long j=0;j<n;j++){
                x = a[j];
                while(x!=req){
                    if(x+1<req){
                        k = false;
                        break;
                    } 
                    op++;
                    if(x%2==0) x/=2;
                    else x++;
                }
                if(k==false) break;
            }
            if(k==true){
                // cout<<p[i]<<"-"<<op<<" ";
                minans = min(minans,op);
            }
            
        }
        cout<<minans<<endl;
    }

    return 0;
}