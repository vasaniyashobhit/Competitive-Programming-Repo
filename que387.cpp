#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> a(n+1);
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        a[x].push_back(i);
    }
    
    for(int i=1;i<=n;i++){
        int m = a[i].size();
        int cnt=0;
        if(m==0) continue;
        for(int j=0;j<m;j++){
            if(a[a[i][j]].empty()) cnt++;
        }
        if(cnt<3){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}