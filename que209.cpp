#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a;  // {count,start}
        for(int i=1;i<=n;i++){
            cout<<"? "<<i<<" "<<n<<" ";
            for(int j=1;j<=n;j++) cout<<j<<" ";
            cout<<endl;
            pair<int,int> p = {0,i};
            cin>>p.first;
            a.push_back(p);
        }

        sort(a.begin(),a.end());
        vector<int> ans;
        ans.push_back(a[n-1].second);
        int i=n-1,j=n-2;
        while(j>=0){
            cout<<"? "<<a[i].second<<" "<<2<<" ";
            cout<<a[i].second<<" "<<a[j].second<<" ";
            cout<<endl;
            int x; cin>>x;
            if(x==2){
                ans.push_back(a[j].second);
                i = j;
                j--;
            }
            else{
                j--;
            }
        }
        cout<<"! "<<ans.size()<<" ";
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;

    }

    return 0;
}