#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int l=0;
        for(int r=0;r<n;r++){
            int req = (r-l+1);
            while(req>a[l]){
                l++;
                req = r-l+1;
            }
            cout<<req<<" ";
        }
        cout<<endl; 
    }

    return 0;
}