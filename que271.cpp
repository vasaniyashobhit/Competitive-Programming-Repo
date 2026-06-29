#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,a; cin>>n>>a;
        vector<int> v(n);
        for(int &it:v) cin>>it;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(v[i]<a) cnt1++;
            else if(v[i]>a) cnt2++;
        }

        if(cnt1>=cnt2) cout<<a-1<<endl;
        else cout<<a+1<<endl;
    }

    return 0;
}