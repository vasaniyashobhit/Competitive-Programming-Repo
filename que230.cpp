#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        bool k = true;
        if((s[0]=='0' && s[1]=='1') || (s[n-1]=='0' && s[n-2]=='1')){
            k = false;
        }
        for(int i=1;i<n-1;i++){
            if(s[i]=='0' && s[i-1]=='1' && s[i+1]=='1'){
                k = false;
                break;
            }
        }
        if(k==false){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                cout<<(i+1)<<" ";
                i++;
            }
            else{
                int l = i;
                while(s[i]=='0' && i<n) i++;
                int r = i-1;
                for(int j=r;j>=l;j--){
                    cout<<(j+1)<<" ";
                }
            }
        }
        cout<<endl;
    }

    return 0;
}