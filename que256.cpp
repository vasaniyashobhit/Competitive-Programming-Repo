#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        bool k1 = false; // even
        bool k2 = false; // odd
        for(int i=0;i<n;i++){
            if(a[i]%2==0) k1 = true;
            else k2 = true;
        }

        if(k1==true && k2==true){
            sort(a.begin(),a.end());
        }

        for(auto it:a) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}