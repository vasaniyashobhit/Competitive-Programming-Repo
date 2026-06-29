#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b;
        for(int &it:a) cin>>it;
        int curr = a[0], currsi = 1;
        for(int i=1;i<n;i++){
            if(a[i]!=curr){
                b.push_back(currsi);
                curr = a[i];
                currsi = 1;
            }
            else{
                currsi++;
            }
        }
        b.push_back(currsi);
        sort(b.begin(),b.end());
        int nn = b.size();
        int ans = 0;
        for(int i=0;i<nn;i++){
            int nos = b[i]*(nn-i);
            ans = max(ans,nos);
        }
        cout<<ans<<endl;
    }

    return 0;
}