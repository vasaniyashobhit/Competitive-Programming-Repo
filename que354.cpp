#include<bits/stdc++.h>
using namespace std;

bool check(int j, int i){
    for(int k=0;k<i;k++){
        if((j&(1<<k))==0) return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int siz = (1<<n)-1;
        vector<int> a(siz+2,0);
        vector<int> ans;
        //cout<<siz<<endl;

        for(int i=n;i>0;i--){
            set<int> st;
            for(int j=0;j<=siz;j++){
                if(a[j]==1) continue;
                if(check(j,i)){
                    st.insert(j);
                    a[j]=1;
                }
            }
            for(auto it:st) ans.push_back(it);
            //cout<<i<<"-";
            //for(auto it:ans) cout<<it<<" ";
            //cout<<endl;
            st.clear();
        }

        //ans.push_back(0);
        for(int i=0;i<=siz;i++){
            if(a[i]==0) ans.push_back(i);
        }
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
        
        
    }

    return 0;
}