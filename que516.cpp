#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        int sum = 0;
        int m = a[0];
        for(int i=0;i<n;i++){
            m = min(m,a[i]);
            sum += m;
        }
        cout<<sum<<endl;
    }

    return 0;
}