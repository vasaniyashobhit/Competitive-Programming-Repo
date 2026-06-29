#include<bits/stdc++.h>
using namespace std;

int check(char c, string s, int n){
    int cnt=0;
    int l=0,r=n-1;
    while(l<=r){
        if(s[l]==s[r]){
            l++;
            r--;
        }
        else if(s[l]==c){
            l++;
            cnt++;
        }
        else if(s[r]==c){
            r--;
            cnt++;
        }
        else{
            return -1;
        }
    }

    return cnt;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        int minans = 1e6;
        for(int i=97;i<=122;i++){
            char c = char(i);
            int ans = check(c,s,n);
            if(ans!=-1){
                minans = min (ans,minans);
            }
        }
        if(minans>=1e6)cout<<-1<<endl;
        else cout<<minans<<endl;
    }

    return 0;
}
