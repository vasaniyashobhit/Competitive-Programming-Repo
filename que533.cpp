#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> &a,long long n,long long k, long long req){

    for(int i=0;i<n;i++){
        if(a[i]>=req) return true;
    }

    bool ans=false;
    for(long long i=0;i<n;i++){
        
        vector<long long> b(n);
        for(int j=0;j<n;j++) b[j] = a[j];

        long long op = k;
        if(b[i]>=req){
            ans==true; break;
        }
        long long j = i;
        op -= (req-b[j]);
        b[j] = req;
        while(j+1<n && b[j+1] < b[j]-1){
            op = op - (b[j]-1 - b[j+1]);
            b[j+1] = b[j]-1;
            j++;
        }
        if(op>=0 && a[n-1]==b[n-1]){
            //cout<<b[i]<<"-hello";
            ans=true;
            break;
        }
    }

    return ans;
}

int main(){
    int t; cin>>t; 
    while(t--){
        long long n,k; cin>>n>>k;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        //cout<<"hello"<<" ";

        long long l=1,r=1e9;
        long long ans = -1;
        while(l<=r){
            //cout<<"hello"<<" ";
            int mid = l + (r-l)/2;
            if(check(a,n,k,mid)){
                //cout<<mid<<" ";
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout<<ans<<endl;
    }

    return 0;
}