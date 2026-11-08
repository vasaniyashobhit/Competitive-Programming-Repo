#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> a(n);
        vector<int> b(n);

        for(int i=0;i<n-1;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        a[n-1] = 1;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int i = n-1;int j=n-1;
        int ans = 0;
        while(i>=0 && j>=0){
            if(a[i]<b[j]){
                j--;
                ans++;
            }
            i--;
        }
        cout<<n-ans<<endl;
    }
}