#include<bits/stdc++.h>
using namespace std;

int findind(map<int,vector<int>> mp,int num, int startind){
        if(mp.find(num)==mp.end()) return -1;
        else if(mp[num].back()<startind) return -1;
        int low = 0,high = mp[num].size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mp[num][mid]>=startind){
                ans = mp[num][mid];
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
}

int main(){
    int n,m; cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int &it:a) cin>>it;
    for(int &it:b) cin>>it;


    map<int,vector<int>> mp;
    for(int j=0;j<m;j++){
        if(mp.find(b[j])==mp.end()){
            mp[b[j]] = {j};
        }
        else mp[b[j]].push_back(j);
    }

    vector<vector<int>> dp(n,vector<int>(m));
    vector<vector<pair<int,pair<int,int>>>> state(n,vector<pair<int,pair<int,int>>>(m)); 
    
    // base case
    int lastind = -1;
    if(mp.find(a[n-1])!=mp.end()) lastind = mp[a[n-1]].back(); 
    if(lastind==-1){
        for(int j=0;j<m;j++){
            dp[n-1][j] = 0;
            state[n-1][j].first = -1;
            state[n-1][j].second = {-1,-1};
        }
    }
    else{
        for(int j=0;j<m;j++){
            if(j<=lastind){
                dp[n-1][j] = 1;
                state[n-1][j].first = 1;
                state[n-1][j].second = {-1,-1};
            }
            else{
                dp[n-1][j] = 0;
                state[n-1][j].first = 0;
                state[n-1][j].second = {-1,-1};
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            dp[i][j] = dp[i+1][j];
            state[i][j].first = 0;
            state[i][j].second = {i+1,j};

            int index = findind(mp,a[i],j);
            if(index!=-1){
               
                if(index+1<m){
                    int x = 1+dp[i+1][index+1];
                    if(x>dp[i][j]){
                        dp[i][j] = x;
                        state[i][j].first = 1;
                        state[i][j].second = {i+1,index+1};
                    }
                }
                else{
                    int x = 1;
                    if(x>dp[i][j]){
                        dp[i][j] = x;
                        state[i][j].first = 1;
                        state[i][j].second = {-1,-1};
                    }
                }
            }
        }
    }

    cout<<dp[0][0]<<endl;
    int i=0,j=0;
    while(true){
        if(state[i][j].first==1) cout<<a[i]<<" ";
        if(state[i][j].second.first == -1) break;
        auto next = state[i][j].second; 
        i = next.first;
        j = next.second;
    }

    return 0;
}