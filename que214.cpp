#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> x(n);
        vector<int> y(n);
        for(int &it:x) cin>>it;
        for(int &it:y) cin>>it;

        vector<int> d(n);
        for(int i=0;i<n;i++){
            d[i] = y[i]-x[i];
        }
        sort(d.begin(),d.end());

        int count=0;
        int i=0,j=n-1;
        while(i<j){
            while(d[i]+d[j]<0 && (i<j)) i++;
            if(i==j) break;
            else{
                count++;
                j--;
                i++;
            }
            //cout<<"h"<<" ";
        }
        //cout<<"he"<<endl;
        cout<<count<<endl;
    }

    return 0;
}