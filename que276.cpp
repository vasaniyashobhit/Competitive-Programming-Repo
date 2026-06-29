#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,q; cin>>n>>q;
    vector<long long> a(n);
    for(auto &it:a) cin>>it;

    long long sum=0;
    for(int i=0;i<n;i++){
        sum += a[i];
    }

    map<long long,long long> mp;
    long long prev = -1;
    while(q--){
        long long t,ind,x; cin>>t;
        if(t==1){
            cin>>ind>>x;
            if(prev==-1){
                sum += (x-a[ind-1]);
                cout<<sum<<endl;
                a[ind-1] = x;
            }
            else{
                if(mp.find(ind-1)!=mp.end()){
                    sum += x-mp[ind-1];
                    mp[ind-1] = x;
                }
                else{
                    mp[ind-1] = x;
                    sum += (x-prev);
                }
                cout<<sum<<endl;
            }
        }
        else{
            cin>>x;
            sum = n*x;
            cout<<sum<<endl;
            mp.clear();
            prev = x;
        }
    }

    return 0;
}