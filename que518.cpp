#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        for(int i=0;i<n-1;i++){
            if(a[i] > a[i+1]){
                swap(a[i],a[i+1]);
                a[i+1] += a[i];
            }
        }
        cout<<a[n-1]<<endl;
    }

    return 0;
}