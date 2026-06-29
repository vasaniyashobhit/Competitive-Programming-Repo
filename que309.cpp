#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long &it:a) cin>>it;
        for(long long &it:b) cin>>it;

        vector<long long> c(n);
        for(int i=0;i<n;i++) c[i] = a[i]-b[i];

        long long largest = -(1e10+1);
        for(int i=0;i<n;i++) largest = max(largest,c[i]);
        long long count=0;
        vector<long long> ans;
        for(int i=0;i<n;i++){
            if(c[i]==largest){
                count++;
                ans.push_back(i+1);
            }
        } 
        cout<<count<<endl;
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}