#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        bool ans = true;
        for(int i=1;i<n;i++){
            if(a[i]%2==0 && a[i-1]%2==0){
                ans = false;
                break;
            }
            if(a[i]%2!=0 && a[i-1]%2!=0){
                ans = false;
                break;
            }
        }
        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}