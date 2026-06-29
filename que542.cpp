#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int,int> mp1;
        map<int,int> mp2;

        bool k = true;
        for(int i=0;i<n;i++){
            int a,b; cin>>a>>b;
            if(a==b) k = false;

            if(mp1.find(a)==mp1.end() && mp1.find(b)==mp1.end()){
                mp1[a] = 1;
                mp1[b] = 1;
            }
            else if(mp2.find(a)==mp2.end() && mp2.find(b)==mp2.end()){
                mp2[a] = 1;
                mp2[b] = 1;
            }
            else k = false;
        }

        if(k==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}