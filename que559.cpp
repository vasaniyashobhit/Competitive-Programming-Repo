#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        if(n==1){
            cout<<0<<endl;
            continue;
        }

        reverse(a.begin(),a.end());
        int cnt=0;
        for(int i=1;i<n;i*=2){
            for(int j=i;j<n && j<i*2;j++){
                if(a[j]!=a[0]){
                    cnt++;
                    break;
                }
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}