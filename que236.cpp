#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        if(n==1){
            cout<<0<<endl;
            continue;
        }
        
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            if(s[i]=='a') a.push_back(i);
            else b.push_back(i);
        }

        int n1 = a.size(),n2 = b.size();
        if(n1<2 || n2<2){
            cout<<0<<endl;
            continue;
        }
        
        int mida = n1/2;
        int k=a[mida];
        int k1 = k,k2=k;
        int ans1=0;
        for(int i=mida+1;i<n1;i++){
            k1++;
            ans1 += abs(a[i]-k1);
        }
        for(int i=mida-1;i>=0;i--){
            k2--;
            ans1 += abs(k2-a[i]);
        }
        //cout<<ans1<<endl;

        int midb = n2/2;
        k = b[midb];
        k1=k,k2=k;
        int ans2=0;
        for(int i=midb+1;i<n2;i++){
            k1++;
            ans2 += abs(b[i]-k1);
        }
        for(int i=midb-1;i>=0;i--){
            k2--;
            ans2 += abs(k2-b[i]);
        }
        cout<<min(ans1,ans2)<<endl;

    }

    return 0;
}