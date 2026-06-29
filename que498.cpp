#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    vector<int> nger(n);
    vector<int> ngel(n);

    // ngel
    stack<pair<int,int>> st;
    ngel[0] = -1;
    st.push({a[0],0});
    for(int i=1;i<n;i++){
        while((!st.empty()) && st.top().first<=a[i]) st.pop();
        if(st.empty()) ngel[i] = -1;
        else{
            ngel[i] = st.top().second;
        }
        st.push({a[i],i});
    }
   
    // nger
    stack<pair<int,int>> stt;
    nger[n-1] = -1;
    stt.push({a[n-1],n-1});
    for(int i=n-2;i>=0;i--){
        while((!stt.empty()) && stt.top().first<=a[i]) stt.pop();
        if(stt.empty()) nger[i] = -1;
        else nger[i] = stt.top().second;
        stt.push({a[i],i});
    }
    
    //
    vector<pair<int,int>> b;
    for(int i=0;i<n;i++) b.push_back({a[i],i});
    sort(b.begin(),b.end());

    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        int ind = b[i].second;
        if(nger[ind]!=-1){
            dp[nger[ind]] = max(dp[nger[ind]],dp[ind]+1);
        }
        if(ngel[ind]!=-1){
            dp[ngel[ind]] = max(dp[ngel[ind]],dp[ind]+1);
        }
    }
    int ans = 0;
    for(auto it:dp) ans = max(ans,it);
    cout<<ans<<endl;

    return 0;
}