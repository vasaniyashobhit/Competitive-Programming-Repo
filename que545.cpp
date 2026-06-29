#include<bits/stdc++.h>
using namespace std;

vector<string> p = {"abc","acb","bac","bca","cab","cba"};

int main(){
    int n,m; cin>>n>>m;
    string s; cin>>s;
    vector<vector<int>> change(6,vector<int>(n,0));
    vector<vector<int>> pref(6,vector<int>(n,0));

    for(int i=0;i<6;i++){
        for(int j=0;j<n;j++){
            if(s[j]!=p[i][j%3]) change[i][j]++;
        }
    }

    for(int i=0;i<6;i++){
        pref[i][0] = change[i][0];
        for(int j=1;j<n;j++){
            pref[i][j] = pref[i][j-1];
            if(change[i][j]==1) pref[i][j]++;
        }
    }

    // for(int j=0;j<6;j++){
    //     for(int i=0;i<n;i++) cout<<change[0][i]<<" ";
    //     cout<<endl;
    //     for(int i=0;i<n;i++) cout<<pref[0][i]<<" ";
    //     cout<<endl;
    //     cout<<endl;
    // }

    

    while(m--){
        int l,r; cin>>l>>r;
        l--;r--;
        int minans = 1e6;
        for(int i=0;i<6;i++){
            int ans = pref[i][r];
            if(l>0) ans -= pref[i][l-1];
            minans = min(ans,minans);
        }
        cout<<minans<<endl;
    }


    return 0;
}