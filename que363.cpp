#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin>>t;
    while(t--){
        long long n,m; cin>>n>>m;
        vector<pair<long long,long long>> a(n,{0,0});   // {a,index}
        for(long long i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second = i;
        }

        if(!(m<=n/2)){
            cout<<-1<<endl;
            continue;    
        }
        else if(m==0){
            sort(a.begin(),a.end());
            long long t=0;
            for(long long i=0;i<n-2;i++){
                t += a[i].first;
            }
            //cout<<"hello"<<endl;
            if(a[n-1].first-t>a[n-2].first){
                cout<<-1<<endl;
                continue;
            }
            //cout<<t<<endl;
            vector<pair<long long, long long>> ans;
            long long i=0,health=a[n-1].first;
            while(health>a[i].first){
                health-=a[i].first;
                ans.push_back({a[i].second,a[n-1].second});
                i++;
            }
            while(i<=n-2){
                ans.push_back({a[i].second,a[i+1].second});
                i++;
            }
            cout<<ans.size()<<endl;
            for(auto it:ans) cout<<it.first+1<<" "<<it.second+1<<endl;

            continue;
        }
        
        cout<<n-m<<endl;

        sort(a.begin(),a.end());
        for(long long i=0;i<n-2*m;i++){
            cout<<a[i].second+1<<" "<<a[i+1].second+1<<endl;
        }
        for(long long i=n-2*m;i<n-m;i++){
            cout<<a[i+m].second+1<<" "<<a[i].second+1<<endl;
        }

    }

    return 0;
}