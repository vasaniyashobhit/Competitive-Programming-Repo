#include<bits/stdc++.h>
using namespace std;

bool check(long long s, long long m, long long op){
    double reqsum=0;
    double sum=0;
    for(long long i=63;i>=0;i--){
        if((s>>i)&1==1){
            reqsum += (1ll<<i);
        }
        //cout<<reqsum<<endl;
        if((m>>i)&1==1){
            sum = op;
            sum *= (1ll<<i);
            if(sum>=reqsum) reqsum=0;
            else reqsum -= sum;
            sum=0;
        }
    }
    if(reqsum>0) return false;
    return true;
    
}

int main(){
    int t;cin>>t;
    while(t--){
        long long s,m; cin>>s>>m;

        bool k = true;
        for(long long j=0;j<=63;j++){
            if((m>>j)&1) break;
            if((s>>j)&1){
                k = false;
                break;
            }
        }
        if(k==false){
            cout<<-1<<endl;
            continue;
        }

        long long ans=-2;
        long long l=1,r=1e18;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(s,m,mid)){
                r = mid-1;
                ans = mid;
                //cout<<1<<" ";
            }
            else l = mid+1;
        }
        cout<<ans<<endl;

    }
}