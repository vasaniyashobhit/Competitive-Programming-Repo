#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        map<int,int> mp;
        int sum = 0;
        mp[0] = 1;

        long long ans = 0;
        for(int i=0;i<n;i++){
            sum += (s[i]-'0');
            int diff = (i+1)-sum;
            if(mp.find(diff)!=mp.end()){
                ans += mp[diff];
                mp[diff]++;
            }
            else mp[diff] = 1;
        }

        cout<<ans<<endl;
    }
}