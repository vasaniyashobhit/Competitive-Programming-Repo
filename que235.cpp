#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a;
        set<int> st;
        int cnt1 = 0;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            st.insert(x);
            if(x==k) cnt1++;
        }
        for(int it:st){
            a.push_back(it);
        }
        auto it = upper_bound(a.begin(),a.end(),k-1);
        int cnt2 = it-a.begin();
        cnt2 = k - cnt2;
        cout<<max(cnt1,cnt2)<<endl;
    }

    return 0;
}