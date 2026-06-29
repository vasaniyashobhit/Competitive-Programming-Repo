#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;

        bool ans = true;
        for(int i=0;i<k;i++){
            bool zr=false,on=false;
            for(int j=i;j<n;j+=k){
                if(s[j]=='1') on=true;
                else if(s[j]=='0') zr = true;
            }
            
            if(zr==true && on==true){
                ans = false;
                break;
            }
            else if(zr==true || on==true){
                if(zr==true) s[i] = '0';
                else s[i] = '1';
            }
        }
        if(ans==false){
            cout<<"NO"<<endl;
            continue;
        }
        int cnt0=0,cnt1=0;
        for(int i=0;i<k;i++){
            if(s[i]=='1') cnt1++;
            else if(s[i]=='0') cnt0++;
        }
        if(cnt1>k/2 || cnt0>k/2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }

    return 0;
}