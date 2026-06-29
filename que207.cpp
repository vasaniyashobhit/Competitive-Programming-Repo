#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int &it:a) cin>>it;

        bool ans = false;
        vector<int> hash(105,0);
        for(int i=0;i<n;i++){
            hash[a[i]]++;
            if(hash[a[i]]>1){
                ans = true;
                break;
            }
        }

        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}