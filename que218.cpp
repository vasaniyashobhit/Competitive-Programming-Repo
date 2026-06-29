#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<char>> a(n,vector<char>(n));
        for(auto &it:a){
            for(auto &itt:it) cin>>itt;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int on=0;
                if(a[i][j]=='1') on++;
                if(a[j][n-i-1]=='1') on++;
                if(a[n-i-1][n-j-1]=='1') on++;
                if(a[n-j-1][i]=='1') on++;
                ans += min(on%4,(4-on)%4);
                a[i][j] = a[j][n-i-1] = a[n-i-1][n-j-1] = a[n-j-1][i] = '1';
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}