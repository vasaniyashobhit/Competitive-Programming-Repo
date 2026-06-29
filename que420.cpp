#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        if(n==1){
            cout<<a[0]<<endl;
            break;
            
        }
        
        vector<vector<int>> b(n+1);
        for(int i=0;i<n;i++){
            b[a[i]].push_back(i+1);
        }

        vector<int> ans(n+2,-1);
        for(int i=1;i<=n;i++){
            int m = b[i].size();
            if(m==0) continue;
            int maxgap = b[i][0]-1;
            maxgap = max(n-b[i][m-1],maxgap);
            for(int j=1;j<m;j++){
                maxgap = max(maxgap,b[i][j]-b[i][j-1]-1);
            }
            if(ans[maxgap+1]==-1) ans[maxgap+1] = i;
        }
        int sm = -1;
        for(int i=1;i<=n;i++){
            if(ans[i]!=-1){
                if(sm==-1) sm = ans[i];
                else sm = min(ans[i],sm);
                cout<<sm<<" ";
            }
            else cout<<sm<<" ";
        }
        cout<<endl;
    }

    return 0;
}