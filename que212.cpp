#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;

        int len=0,maxlen=0;
        int l=0,r=0;
        while(r<n && l<n){
            if(s[r]=='0'){
                r++;
                l = r;
                continue;
            }
            len = r-l+1;
            maxlen = max(len,maxlen);
            r++;
        }

        if(maxlen>=k){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            int on=0,zr=0;
            for(int i=0;i<n;i++){
                if(s[i]=='1') on++;
                else zr++;
            }
            int k1=1,k2 = on+1;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    cout<<k1<<" ";
                    k1++;
                }
                else{
                    cout<<k2<<" ";
                    k2++;
                }
            }
            cout<<endl;
        }
    }

    return 0;
}