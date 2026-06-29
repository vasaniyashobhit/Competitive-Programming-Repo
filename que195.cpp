#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int &it:a) cin>>it;
        for(int &it:b) cin>>it;
        
        for(int i=0;i<n;i++){
            a[i] = a[i]%k;
            b[i] = b[i]%k;

            if(a[i]>k/2) a[i] = k-a[i];
            if(b[i]>k/2) b[i] = k-b[i];
        }
        map<int,int> mpa;
        map<int,int> mpb;
        for(int i=0;i<n;i++){
            if(mpa.find(a[i])==mpa.end()){
                mpa[a[i]] = 1;
            }
            else mpa[a[i]]++;

            if(mpb.find(b[i])==mpb.end()){
                mpb[b[i]] = 1;
            }
            else mpb[b[i]]++;
        }
        // for(auto it:a) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:b) cout<<it<<" ";
        // cout<<endl;

        bool ans = true;
        for(int i=0;i<n;i++){
            if(mpa[a[i]]!=mpb[a[i]]){
                ans = false;
                break;
            }
            if(mpa[b[i]]!=mpb[b[i]]){
                ans = false;
                break;
            }
        }
        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}