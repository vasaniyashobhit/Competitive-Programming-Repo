#include<bits/stdc++.h>
using namespace std;

int main(){
    
        long long n,k1,k2; cin>>n>>k1>>k2;
        vector<long long> a(n);
        vector<long long> b(n);
        for(long long &it:a) cin>>it;
        for(long long &it:b) cin>>it;

        multiset<long long> st;
        long long d=0;
        for(int i=0;i<n;i++){
            st.insert(abs(a[i]-b[i]));
            d += abs(a[i]-b[i]);
        }

        if(d>(k1+k2)){
            for(int i=1;i<=(k1+k2);i++){
                long long num = *(st.rbegin());
                st.erase(--st.end());
                num--;
                st.insert(num);
            }
            long long ans=0;
            for(auto it:st) ans += (it*it);
            cout<<ans<<endl;
        }
        else if(d==(k1+k2)){
            cout<<0<<endl;
        }
        else{
            if((k1+k2-d)%2==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
        
    

    return 0;
}