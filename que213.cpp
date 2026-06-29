#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int &it:a) cin>>it;

        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(mp.find(a[i])==mp.end()){
                mp[a[i]] = {i};
            }
            else{
                mp[a[i]].push_back(i);
            }
        }
        vector<pair<int,int>> intrvl;
        for(auto it:mp){
            int k = it.first;
            int i=0,j=k-1;
            while(j<it.second.size()){
                intrvl.push_back({it.second[j-k+1],it.second[j]});
                j++;
            }
        }
        sort(intrvl.begin(),intrvl.end());

        vector<pair<int,pair<int,int>>>critical;
        int curr = a[intrvl[0].first];
        pair<int,int> currint = {0,intrvl[0].second};
        for(int i=1;i<intrvl.size();i++){
            int present = a[intrvl[i].first];
            pair<int,int> presentint = {intrvl[i].first,intrvl[i].second};
            if(currint.second<presentint.second){
                currint.first = presentint.first;
                currint.second = presentint.second;
                curr = present;
                continue;
            }
            if(curr>present){
                if(presentint.second<currint.second){
                    critical.push_back({currint.second-presentint.second,{presentint.second+1,currint.second-1}});
                }
            }
            else if(present>=curr){
                if(presentint.second<=currint.second){
                    curr = present;  
                }
                else{
                    critical.push_back({presentint.second-currint.second,{currint.second+1,presentint.second-1}});
                    curr = present;
                }
                currint.first = presentint.first;
                currint.second = presentint.second;
            }
        }

        sort(critical.begin(),critical.end());
        map<pair<int,int>,int> ctmp;
        for(int i=0;i<critical.size();i++){
            
        }
    }

    return 0;
}