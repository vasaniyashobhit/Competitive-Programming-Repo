#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> u(n);
        for(long long &it:u) cin>>it;
        vector<long long> s(n);
        for(long long &it:s) cin>>it;


        map<long long,vector<long long>> mp;
        for(int i=0;i<n;i++){
            mp[u[i]].push_back(s[i]);
        }

        vector<long long> ans(n+1,0);

        for(auto &i:mp){

            sort(i.second.begin(),i.second.end(),greater<int>());
            for(int j=1;j<i.second.size();j++){
                i.second[j] += i.second[j-1];
            }

            long long m = i.second.size();
            for(long long k=1;k<=m;k++){
                long long students_included = (m / k) * k;
                ans[k] += i.second[students_included - 1];
            }
            
        }

        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;


    }

    return 0;
}