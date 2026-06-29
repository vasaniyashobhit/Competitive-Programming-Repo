#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        
        set<int> st;
        
        long long ans=0;
        for(int i=0;i<n;i++){
            if(st.size()>0){
                int num = a[i];
                int lar = *(st.rbegin());
                int sm = *(st.begin());
                if((lar>num+k) || (sm<num-k)){
                    ans++;
                    st.clear();
                }
                else st.insert(num);
            }
            else st.insert(a[i]);
        }
        cout<<ans<<endl;
    }

}
