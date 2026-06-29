#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        sort(a.begin(),a.end());

        //cout<<"hello"<<endl;
        int minans = 1000;
        for(int i=0;i<n;i++){
            int left=0,right=0;
            for(int j=0;j<n;j++){
                if(a[j]==a[i]) continue;
                if(j<i) left++;
                if(j>i) right++;
            }
            int ans = min(left,right);
            ans += abs(left-right);
            minans = min(ans,minans);
        }
        cout<<minans<<endl;
    }

    return 0;
}