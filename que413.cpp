#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> x(n);
        vector<long long> y(n);
        for(int i=0;i<n;i++){
            cin>>x[i];
            cin>>y[i];
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        long long cnt1=0,cnt2=0;
        if(n%2==0){
            long long mid = n/2;
            cnt1 = x[mid]-x[mid-1]+1;
            cnt2 = y[mid]-y[mid-1]+1;
            cout<<(cnt1*cnt2)<<endl;
            //cout<<cnt1<<" "<<cnt2<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    
    return 0;
}