#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k,x; cin>>n>>k>>x;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;
    sort(a.begin(),a.end());

    vector<long long> g;
    long long gaps=0;
    for(int i=0;i<n-1;i++){
        if((a[i+1]-a[i])>x){
            gaps++;
            g.push_back(a[i+1]-a[i]-1);
        }
    }
    long long ans = 0;
    sort(g.begin(),g.end());
    for(int i=0;i<g.size();i++){
        long long req = g[i]/x;
        if(k>=req){
            ans++;
            k -= g[i]/x;
        }
        else break;
    }
    gaps = gaps-ans;
    cout<<gaps+1<<endl;

    return 0;
}