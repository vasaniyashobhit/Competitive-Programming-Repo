#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int t; cin>>t;
        while(t--){
            int n; cin>>n;
            set<int> st;
            for(int i=1;i<=n;i++){
                st.insert(i);
            }
            vector<int> ans(n+1,0);
            cout<<"h1"<<endl;
            while(st.size()>0){
                int x = *st.begin();
                st.erase(st.begin());
                for(auto it:st){
                    if(x^it<=n){
                        ans[x] = it;
                        ans[it] = x;
                        st.erase(it);
                        break;
                    }
                }
            }
            cout<<"h2"<<endl;
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<endl;

        }
    }

    return 0;
}