#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m; cin>>n>>m;
        vector<long long>a(m);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());

        vector<long long> gp(m,0);
        for(long long i = 0;i<m-1;i++){
            gp[i] = a[i+1] - a[i] -1;
        }
        gp[m-1] = (n-a[m-1]) + (a[0]-1);
        sort(gp.begin(),gp.end());
        // for(auto it:gp) cout<<it<<" ";
        // cout<<endl;
        long long p=0,d=0;
        for(int i=m-1;i>=0;i--){
            if(i!=m-1) gp[i] -= 2*d;
            if(gp[i]>=3){
                p += gp[i]-1;
                d += 2;
            }
            else if(gp[i]>=1){
                p += 1;
                d += 1;
            }
            else if(gp[i]<0) break;
           
            //cout<<p<<" ";
        }
        //cout<<endl;
        long long inf = n - p;
        cout<<inf<<endl;
    }

    return 0;
}