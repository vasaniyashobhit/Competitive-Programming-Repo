#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(a[i],maxi);
        }
        cout<<(n*maxi)<<endl;
    }

    return 0;
}