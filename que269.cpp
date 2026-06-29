#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        sort(a.begin(), a.end());
        bool ans = true;
        for(int i=1;i<n-1;i+=2){
            if(a[i]!=a[i+1]){
                ans = false;
                break;
            }
        }

        if(ans==true) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
    }

    return 0;
}