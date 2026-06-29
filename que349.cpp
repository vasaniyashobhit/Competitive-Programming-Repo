#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k,q; cin>>n>>k>>q;
        vector<vector<int>> a(q,vector<int>(3,0));
        for(auto &it:a){
            for(auto &itt:it) cin>>itt;
        }

        vector<pair<int,int>> mini(n,{0,0});
        for(int i=0;i<q;i++){
            for(int j=a[i][1];j<=a[i][2];j++){
                if(a[i][0]==1) mini[j-1].first = 1;
                else mini[j-1].second = 1;
            }
        }

        set<int> st;
        for(int i=0;i<n;i++) st.insert(i);
        vector<int> ans(n,-1);

        for(int i=0;i<q;i++){
            if(a[i][0]==1){
                for(int j=a[i][1];j<=a[i][2];j++){
                    st.erase(j-1);
                }
            }
        }

        int i=0;
        for(auto it:st){
            ans[it] = i;
            i++;
            i%=k;
        }

        for(int j=0;j<n;j++){
            if(ans[j]==-1){
                if(mini[j].first==1 && mini[j].second==1) ans[j]=k+1;
                else ans[j] = k;
            }
        }
        
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}