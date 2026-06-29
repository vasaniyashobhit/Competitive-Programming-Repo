#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(int &it:a) cin>>it;
    for(int &it:b) cin>>it;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<int>> choice(n+1, vector<int>(m+1, 0)); // 0=skip a, 1=match, 2=skip b
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                choice[i][j] = 1; // matched
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    choice[i][j] = 0; // skip a[i]
                }
                else{
                    dp[i][j] = dp[i][j-1];
                    choice[i][j] = 2; // skip b[j]
                }
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
    // Reconstruct
    vector<int> result;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(choice[i][j] == 1){
            result.push_back(a[i-1]);
            i--; j--;
        }
        else if(choice[i][j] == 0){
            i--;
        }
        else{
            j--;
        }
    }
    
    reverse(result.begin(), result.end());
    for(int x : result) cout << x << " ";
    
    return 0;
}