#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x; cin>>n>>x;
        vector<vector<long long>> a(n,vector<long long>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }

        long long sum=0;
        long long maxi=0;
        for(int i=0;i<n;i++){
            long long m = (a[i][0]*(a[i][1])) - a[i][2];
            maxi = max(m,maxi);
            if(a[i][1]>1){
                sum += a[i][0]*(a[i][1]-1);
            }
        }
        if(sum>=x) cout<<0<<endl;
        else{
            if(maxi<=0){
                cout<<-1<<endl;
                continue;
            }
            long long req = x-sum;
            long long ans = req/maxi;
            if(req%maxi!=0) ans++;
            cout<<ans<<endl;
        }
    } 

    return 0;
}