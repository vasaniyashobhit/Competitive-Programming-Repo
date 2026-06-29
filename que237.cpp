#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        string s; cin>>s;

        if(n==1){
            cout<<0<<endl;
            continue;
        }
        
        vector<long long> a;
        vector<long long> b;
        for(long long i=0;i<n;i++){
            if(s[i]=='a') a.push_back(i);
            else b.push_back(i);
        }

        long long n1 = a.size(),n2 = b.size();
        if(n1<2 || n2<2){
            cout<<0<<endl;
            continue;
        }

        long long mida=0,r,l;
        long long k1,k2;
        if(n1%2==0){
            mida = (a[n1/2] + a[(n1/2)-1])/2;
            k1 = mida+1;
            k2 = mida;
            r = n1/2;
            l = n1/2 - 1;
        }
        else{
            mida = a[n1/2];
            k1 = mida+1;
            k2 = mida-1;
            r = n1/2+1;
            l = n1/2-1;
        }
        //cout<<mida<<" "<<l<<" "<<r<<" "<<k1<<" "<<k2<<endl;
        long long ans1=0;
        for(long long i=r;i<n1;i++){
            ans1 += abs(a[i]-k1);
            k1++;
        }
        for(long long i=l;i>=0;i--){
            ans1 += abs(k2-a[i]);
            k2--;
        }

        //// alkdjshfasdf

        long long midb=0,ans2=0;
        if(n2%2==0){
            midb = (b[n2/2] + b[(n2/2)-1])/2;
            k1 = midb+1;
            k2 = midb;
            r = n2/2;
            l = n2/2 - 1;
        }
        else{
            midb = b[n2/2];
            k1 = midb+1;
            k2 = midb-1;
            r = n2/2+1;
            l = n2/2-1;
        }
        //cout<<midb<<" "<<l<<" "<<r<<" "<<k1<<" "<<k2<<endl;
        for(long long i=r;i<n2;i++){
            ans2 += abs(b[i]-k1);
            k1++;
        }
        for(long long i=l;i>=0;i--){
            ans2 += abs(k2-b[i]);
            k2--;
        }
        cout<<min(ans1,ans2)<<endl;
        //cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}