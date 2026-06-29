#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long k,x; cin>>k>>x;
        long long cnt=0,i=0,count=0;
        while((x&(1ll<<i))==0){
            cnt++;
            i++;
        }
        count = k-cnt;
        cout<<count<<endl;
        vector<int> ans;
        for(int i=cnt+1;i<=k;i++){
            //cout<<(x&(1ll<<i))<<" ";
            if((x&(1ll<<i))==0){
                ans.push_back(1);
            }
            else{
                ans.push_back(2);
            }
        }
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;

    }
    return 0;
}