#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> a(n);
    vector<int> parent(n);
    vector<int> ver(n,0);
    for(int i=0;i<n;i++){
        int p,c; cin>>p>>c;
        if(p!=-1){
            p--;
            a[i].push_back(p);
            a[p].push_back(i);
        }
        ver[i] = c;
        parent[i] = p;
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(ver[i]==1){
            bool k = true;
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]!=parent[i] && ver[a[i][j]]==0) k=false;
            }
            if(k==true) ans.push_back(i+1);
        }
        
    }
    if(ans.empty()) cout<<-1<<endl;
    else{
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}