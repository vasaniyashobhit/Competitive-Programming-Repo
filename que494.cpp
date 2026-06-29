#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &visited, vector<vector<char>> &maze, int n, int m){
    queue<pair<int,int>> q;
    q.push({n-1,m-1});
    visited[n-1][m-1] = 1;
    while(!q.empty()){
        //cout<<"hello1"<<endl;
        pair<int,int> node = q.front();
        int i = node.first;
        int j = node.second;
        if(i>0 && maze[i-1][j]!='#' && visited[i-1][j]==0){
            visited[i-1][j] = 1;
            q.push({i-1,j});
        }
        if(j>0 && maze[i][j-1]!='#' && visited[i][j-1]==0){
            visited[i][j-1] = 1;
            q.push({i,j-1});
        }
        if(i<n-1 && maze[i+1][j]!='#' && visited[i+1][j]==0){
            visited[i+1][j] = 1;
            q.push({i+1,j});
        }
        if(j<m-1 && maze[i][j+1]!='#' && visited[i][j+1]==0){
            visited[i][j+1] = 1;
            q.push({i,j+1});
        }
        q.pop();
    }

    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<vector<char>> maze(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>maze[i][j];
            }
        }

        bool ans = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]=='B'){
                    if(i>0 && maze[i-1][j]=='G') ans = false;
                    else if(i>0 && maze[i-1][j]!='B') maze[i-1][j] = '#';
                    //cout<<"hello1"<<endl;

                    if(i<n-1 && maze[i+1][j]=='G') ans = false;
                    else if(i<n-1 && maze[i+1][j]!='B') maze[i+1][j] = '#';

                    if(j>0 && maze[i][j-1]=='G') ans = false;
                    else if(j>0 && maze[i][j-1]!='B') maze[i][j-1] = '#';

                    if(j<m-1 && maze[i][j+1]=='G') ans = false;
                    else if(j<m-1 && maze[i][j+1]!='B') maze[i][j+1] = '#';
                }
            }
        }

        if(n>1 && maze[n-2][m-1]=='B') maze[n-1][m-1]='#';
        if(m>1 && maze[n-1][m-2]=='B') maze[n-1][m-1]='#';

        if(ans==false){
            cout<<"No"<<endl;
            continue;
        }

        vector<vector<int>> visited(n,vector<int>(m));
        if(maze[n-1][m-1]!='#') bfs(visited,maze,n,m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j]=='G' && visited[i][j]==0) ans=false;
            }
        }

        if(ans==true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}