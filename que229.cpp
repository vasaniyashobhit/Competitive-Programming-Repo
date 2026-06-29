#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<map>
#include<set>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        map<int,vector<int>>mp;
        for(int i=1;i<=n;i++){
            int l; cin>>l;
            for(int j=1;j<=l;j++){
                int x; cin>>x;
                if(mp.find(x)==mp.end()){
                    mp[x] = {};
                    mp[x].push_back(i);
                }
                else mp[x].push_back(i);
            }
        }
        for(int i=1;i<=m;i++){
            if(mp.find(i)==mp.end()){
                mp[i] = {};
            }
        }

        bool k = true;
        set<int> st;
        for(int i=1;i<=m;i++){
            if(mp[i].size()==0){
                k = false;
                break;
            }
            if(mp[i].size()==1){
                st.insert(mp[i][0]);
            }
        }
        if(k==false){
            cout<<"NO"<<endl;
        }
        else{
            if((n-st.size())>1){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}