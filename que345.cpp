#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        set<long long> st;
        vector<pair<long long,long long>> b(n);  // {element,index}
        for(int i=0;i<n;i++){
            b[i].first = a[i];
            b[i].second = i;
            st.insert(i);
        }
        sort(b.begin(),b.end());

        long long ans=0;
        for(long long i=0;i<n-1;i++){
            long long index = b[i].second;

            auto rightind = st.upper_bound(index);
            if(rightind==st.end()) rightind = st.begin();
            long long rightindex = *rightind;

            auto leftind = st.lower_bound(index);
            if(leftind==st.begin()) leftind = st.end();
            leftind--;
            long long leftindex=*leftind;

            ans += min(a[leftindex],a[rightindex]);
            st.erase(index);
        }
        cout<<ans<<endl;

    }

    return 0;
}