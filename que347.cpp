#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> b(n);
        for(long long &it:b) cin>>it;
        
        vector<long long> a(n,0);
        a[0] = 1;
        int k=1;
        for(int i=1;i<n;i++){
            int d = b[i]-b[i-1];
            if(i-d==-1){
                a[i] = k+1;
                k++;
            }
            else a[i] = a[i-d];
            //a[i] = a[d];
        }
        for(auto it:a) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}