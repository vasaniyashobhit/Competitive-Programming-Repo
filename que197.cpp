#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int sum=0,l=0,r=0,maxsum=a[0];
        while(r<n){
            sum += a[r];
            if(sum<0){
                l = r+1;
                maxsum = max(sum,maxsum);
                sum = 0;
                r++;
                continue;
            }
            if(l<r && r<n && r>0 && ((a[r]+a[r-1])%2==0)){
                sum = max(a[r],0);
                l = r;
            }
            maxsum = max(sum,maxsum);
            r++;
        }
        cout<<maxsum<<endl;
    }

    return 0;
}