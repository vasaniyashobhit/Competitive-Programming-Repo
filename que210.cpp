#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        long long sum = 0;
        for(int i=1;i<n;i+=2){
            if(i==n-1){
                sum += max(a[i-1]-a[i],0ll);
                break;
            }
            sum += max(a[i-1]+a[i+1]-a[i],0ll);
            if((a[i-1]+a[i+1])>a[i]){
                if(a[i-1]>a[i]){
                    a[i-1] = a[i];
                    a[i+1] = 0;
                }
                else{
                    a[i+1] = a[i]-a[i-1];
                }
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}