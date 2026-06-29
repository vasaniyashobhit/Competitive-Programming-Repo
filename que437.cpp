#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a(n);
        vector<pair<int,int>> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
            b[i].first = a[i].first;
            b[i].second = a[i].second;
        }
        sort(a.begin(),a.end());
        bool k=false;
        int ans = -1;
        int m=0;
        for(int i=0;i<n-1;i++){
            m = max(a[i].second,m);
            if(m<a[i+1].first){
                k = true;
                ans = m;
                break;
            }
        }
        if(k==true){
            for(int i=0;i<n;i++){
                if(b[i].second<=ans) cout<<1<<" ";
                else cout<<2<<" ";
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }

    return 0;
}