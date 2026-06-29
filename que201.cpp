#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k,a,b; cin>>n>>k>>a>>b;
        vector<pair<long long,long long>> v(n,{0,0});
        for(pair<long long,long long>  &it:v){
            cin>>it.first;
            cin>>it.second;
        }

        long long ans1 = abs(v[a-1].first - v[b-1].first) + abs(v[a-1].second - v[b-1].second);
        if(a<=k && b<=k){
            cout<<0<<endl;
        }
        else if(a>k && b>k){
            long long mina = abs(v[0].first - v[a-1].first) + abs(v[0].second - v[a-1].second);
            long long minb = abs(v[0].first - v[b-1].first) + abs(v[0].second - v[b-1].second);
            for(long long i=1;i<k;i++){
                mina = min(mina,abs(v[i].first - v[a-1].first) + abs(v[i].second - v[a-1].second));
                minb = min(minb,abs(v[i].first - v[b-1].first) + abs(v[i].second - v[b-1].second));
            }
            ans1 = min(ans1,mina+minb);
            cout<<ans1<<endl;
        }
        else{
            if(a>k){
                long long mina = abs(v[0].first - v[a-1].first) + abs(v[0].second - v[a-1].second);
                for(long long i=1;i<k;i++){
                    mina = min(mina,abs(v[i].first - v[a-1].first) + abs(v[i].second - v[a-1].second));
                }
                ans1 = min(ans1,mina);
                cout<<ans1<<endl;
            }
            else{
                long long minb = abs(v[0].first - v[b-1].first) + abs(v[0].second - v[b-1].second);
                for(long long i=1;i<k;i++){
                    minb = min(minb,abs(v[i].first - v[b-1].first) + abs(v[i].second - v[b-1].second));
                }
                ans1 = min(ans1,minb);
                cout<<ans1<<endl;
            }
        }
    }

    return 0;
}