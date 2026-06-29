#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,s; cin>>n>>s;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int sum=0;
        for(auto it:a){
            if(it) sum++;
        }
        if(sum<s){
            cout<<-1<<endl;
            continue;
        }

        int l=0,r=0;
        int maxlen=0;
        sum=a[0];
        while(l<n && r<n){
            while(sum<=s && r<n){
                r++;
                sum += a[r];
            }
            maxlen = max(maxlen,r-l);
            sum -= a[l];
            l++;
        }
        cout<<n-maxlen<<endl;
    }

    return 0;
}