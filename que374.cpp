#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        if(a[0]==0 && a[n-1]==0){
            cout<<"Bob"<<endl;
        }
        else cout<<"Alice"<<endl;
    }

    return 0;
}