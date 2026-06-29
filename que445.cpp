#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());

    int x=-1,y=-1;
    bool ans=true;
    for(int i=0;i<n;i++){
        if(a[i].first<=x && a[i].first<=y) ans=false;
        if(a[i].first>x) x = a[i].second;
        else if(a[i].first>y) y = a[i].second;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}