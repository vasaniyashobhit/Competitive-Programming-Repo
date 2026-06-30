#include<bits/stdc++.h>
using namespace std;

long long check(long long lines, long long x, long long k){
    long long msg = 0;
    
    if(lines<=k){
        msg = ((lines)*(lines+1))/2;
        if(msg<=x) return msg;
        return -1;
    }
    //cout<<"hello"<<endl;

    msg = ((k)*(k+1))/2;
    msg += (k*(k-1))/2;
    msg -= ((2*k-lines-1)*(2*k-lines))/2;
    if(msg<=x) return msg;
    return -1;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long k,x; cin>>k>>x;
        long long l = 1,r = 2*k-1;
        long long ans = -1, ansmsg = -1;
        long long msg = -1;
        while(l<=r){
            long long mid = l + (r-l)/2;
            msg = check(mid,x,k);
            if(msg != -1){
                ans = mid;
                ansmsg = msg;
                l = mid+1;
            }
            else r = mid-1;
        }

        
        if(ansmsg<x && ans<(2*k-1)){
            ans++;
        }

        cout<<ans<<endl;
        

    }

    return 0;
}