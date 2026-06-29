#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        sort(a.begin(),a.end());
        int m=0;
        for(int i=0;i<n;i++){
            if(a[i]==m) m++;
        }

        if(m>=(k-1)){
            cout<<(k-1)<<endl;
        }
        else{
            cout<<m<<endl;
        }
    }

    return 0;
}