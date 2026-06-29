#include<bits/stdc++.h>
using namespace std;

int findRoot(vector<int> &parent, vector<int> &rank, int n, int i){
    if(parent[i]==i) return i;
    else{
        parent[i] = findRoot(parent,rank,n,parent[i]);
        return parent[i];
    }
}

void union_node(vector<int> &parent, vector<int> &rank, int n, int i,int j){
    int pi = findRoot(parent,rank,n,i);
    int pj = findRoot(parent,rank,n,j);
    if(pi!=pj){
        if(rank[pi]>rank[pj]){
            parent[pj] = pi;
        }
        else{
            parent[pi] = pj;
            if(rank[pi]==rank[pj]) rank[pj]++;
        }
    }
}

int main(){
    int t=1;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> parent(n);
        vector<int> rank(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i=0;i<m;i++){
            string s; cin>>s;
            int u,v; cin>>u>>v;
            u--;v--;
            if(s=="union") union_node(parent,rank,n,u,v);
            else{
                if(findRoot(parent,rank,n,u)==findRoot(parent,rank,n,v)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

    }
}