#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        string s; cin>>s;

        vector<vector<int>> b(k,vector<int>(30,0));
        for(int i=0;i<n;i++){
            b[i%k][s[i]-'a']++;
        }

        int ans=0;
        for(int i=0;i<k/2;i++){
            int tot=0;
            for(int j=0;j<30;j++){
                tot = max(tot,b[i][j]+b[k-i-1][j]);
            }
            ans += 2*(n/k) - tot;
        }
        if(k%2!=0){
            int tot = 0;
            for(int j=0;j<30;j++){
                tot = max(tot,b[k/2][j]);
            }
            ans += (n/k) - tot;
        }
        cout<<ans<<endl;
    }

    return 0;
}