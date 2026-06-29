#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    long long n,k; cin>>n>>k;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;

    set<long long> st;
    map<long long,long long> mp;
    long long count = 0;
    long long l=0,r=-1;
    long long maxi=0,mini=0;
    while(l<n){
        while(st.empty() || (r<n && abs(maxi-mini)<=k)){
            r++;
            if(r==n) break;
            st.insert(a[r]);
            if(mp.find(a[r])==mp.end()) mp[a[r]]=1;
            else mp[a[r]]++;
            maxi = *(--st.end());
            mini = *(st.begin());
        }
        count += r-l;
        mp[a[l]]--;
        if(mp[a[l]]==0) st.erase(a[l]);
        l++;
        if(l==n) break;
        maxi = *(--st.end());
        mini = *(st.begin());
    }
    cout<<count<<endl;
    

    return 0;
}