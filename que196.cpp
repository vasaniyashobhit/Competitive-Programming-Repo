#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int &it:a) cin>>it;
        for(int &it:b) cin>>it;

        if(a[n-1]!=b[n-1]){
            cout<<"NO"<<endl;
            continue;
        }
        bool ans = true;
        int k=-1;
        for(int i=0;i<n-1;i++){
            if(((a[i]^a[i+1])!=b[i]) && ((a[i]^b[i+1])!=b[i]) && (a[i]!=b[i])){
                ans = false;
                k = i;
                break;
            }
        }
        //cout<<k<<" ";
        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}