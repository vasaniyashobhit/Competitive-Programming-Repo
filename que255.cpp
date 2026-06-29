#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> hash(28,0);
        string s,t; cin>>s>>t;

        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            hash[t[i]-'a']--;
        }

        bool k = true;
        for(int i=0;i<28;i++){
            if(hash[i]!=0) k = false;
        }
        if(k==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}