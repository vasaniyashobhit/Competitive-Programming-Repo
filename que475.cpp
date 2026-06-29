#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    vector<int> h(n);
    vector<int> s(n);
    for(int &it:h) cin>>it;
    for(int &it:s) cin>>it;

    vector<int> dp1(x+1);
    vector<int> dp2(x+1);
    for(int i=0;i<=x;i++){
        if(i>=h[n-1]) dp1[i] = s[n-1];
        else dp1[i]=0;
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=x;j++){
            dp2[j] = dp1[j];
            if(j-h[i]>=0) dp2[j] = max(s[i]+dp1[j-h[i]],dp1[j]);
        }
        for(int j=0;j<=x;j++){
            dp1[j] = dp2[j];
        }
    }
    cout<<dp2[x]<<endl;

    return 0;
}