#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m);
        vector<int> c(m);
        int totalz=0;
        for(int &it:a) cin>>it;
        for(int &it:b) cin>>it;
        for(int &it:c){
            cin>>it;
            if(it==0) totalz++;
        }

        multiset<int> s;
        for(auto it:a) s.insert(it);

        vector<pair<int,int>> nonz(m-totalz,{0,0});
        vector<pair<int,int>> z(totalz,{0,0});

        int p1=0,p2=0;
        for(int i=0;i<m;i++){
            if(c[i]==0){
                z[p1] = {b[i],c[i]};
                p1++;
            }
            else{
                nonz[p2] = {b[i],c[i]};
                p2++;
            }
        }
        

        if(totalz!=0){
            sort(z.begin(),z.end());
        }
        if(totalz!=m){
            sort(nonz.begin(),nonz.end());
        }
        

        int ans = 0;

        int nn = m-totalz;
        for(int i=0;i<nn;i++){
            auto it = s.lower_bound(nonz[i].first);
            if(it==s.end()) break;
            int k = max(*(it),nonz[i].second);
            s.erase(it);
            s.insert(k);
            ans++;
        }
        
        int i=0,j=0;
        for(int it:s){
        
            if(j==totalz) break;
            if(it>=z[j].first){
                ans++;
                j++;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}