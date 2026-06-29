#include<bits/stdc++.h>
using namespace std;

int x[] = {+1,+1,+2,+2,-1,-1,-2,-2};
int y[] = {+2,-2,+1,-1,+2,-2,+1,-1};

vector<vector<long long>> dij(pair<int,int> start,pair<int,int> end){
    vector<vector<long long>> dist(8,vector<long long> (8,1e18));
    priority_queue<pair<long long,pair<int,int>>  , vector<pair<long long,pair<int,int>>>  , greater<pair<long long,pair<int,int>>>> pq;
    dist[start.first][start.second] = 0;
    pq.push({0,{start.first,start.second}});
    while(!pq.empty()){
        pair<long long,pair<int,int>> curr = pq.top();
        pq.pop();
        int nodeweight = curr.first;
        pair<int,int> node = curr.second;

        for(int i=0;i<8;i++){
            pair<int,int> v = {node.first+x[i],node.second+y[i]};
            if(v.first>=8 || v.first<0) continue;
            if(v.second>=8 || v.second<0) continue;

            int edge = node.first*v.first + node.second*v.second;
            if(dist[v.first][v.second]>nodeweight+edge){
                dist[v.first][v.second] = nodeweight+edge;
                pq.push({dist[v.first][v.second],v});
            }
        }
    }

    return dist;
}

int main(){
    pair<int,int> start,end;
    while(cin>>start.first>>start.second>>end.first>>end.second){
        vector<vector<long long>> cost = dij(start,end);
        long long ans = cost[end.first][end.second];
        if(ans==1e18) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    
    return 0;
}