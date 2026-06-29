#include<bits/stdc++.h>
using namespace std;

void bfs(int &count,int start, vector<int> &visited, vector<vector<int>> &adj){
    queue<int> q;
    q.push(start);
    visited[start] = count;
    while(!q.empty()){
        int node = q.front();
        int m = adj[node].size();
        for(int i=0;i<m;i++){
            if(visited[adj[node][i]]==0){
                visited[adj[node][i]] = count;
                q.push(adj[node][i]);
            }
        }
        q.pop();
    }
}

int main(){
    int n,m; cin>>n>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++){
        int cnt; cin>>cnt;
        vector<int> group(cnt);
        for(int &it:group) cin>>it;
        for(int j=0;j<cnt-1;j++){
            adj[group[j]-1].push_back(group[j+1]-1);
            adj[group[j+1]-1].push_back(group[j]-1);
        }
    }

    vector<int> visited(n);
    int count = 0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            count++;
            bfs(count,i,visited,adj);
        }
    }

    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(visited[i])==mp.end()) mp[visited[i]] = 1;
        else mp[visited[i]] ++;
    }

    for(int i=0;i<n;i++){
        cout<<mp[visited[i]]<<" ";
    }
    cout<<endl;

    return 0;
}