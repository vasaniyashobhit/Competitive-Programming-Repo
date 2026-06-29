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

        int dec=0;
        for(int i=0;i<n;i++){
            if(a[i]>b[i]) dec += a[i]-b[i];
        }
        dec++;
        cout<<dec<<endl;
    }

    return 0;
}