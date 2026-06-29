#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<vector<long long>> a(n);
        map<long long,long long> mp;
        for(long long i=0;i<n;i++){
            long long k; cin>>k;
            for(long long j=0;j<k;j++){
                long long x; cin>>x;
                a[i].push_back(x);
            }
        }
        if(n==1){
            cout<<"No"<<endl;
            continue;
        }

        for(auto it:a){
            for(auto itt:it){
                if(mp.find(itt)==mp.end()) mp[itt]=1;
                else mp[itt]++;
            }
        }

        bool m=false;
        for(long long i=0;i<n;i++){
            bool ans = true;
            long long nn = a[i].size();
            for(long long j=0;j<nn;j++){
                if(mp[a[i][j]]==1){
                    ans = false;
                    break;
                }
            }
            if(ans==true){
                m=true;
                break;
            }
        }
        if(m) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}