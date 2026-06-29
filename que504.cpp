#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int lr = 0;
        int sm = 1000;
        for(int i=0;i<n;i++){
            lr = max(lr,a[i]);
            sm = min(sm,a[i]);
        }

        cout<<(lr+1-sm)<<endl;
    }

    return 0;
}