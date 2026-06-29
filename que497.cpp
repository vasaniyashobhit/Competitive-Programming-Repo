#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool check(int a, int b, vector<vector<int>> &adj, vector<int> &visitedelement)
{
    int n = adj[a].size();
    int m = adj[b].size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (visitedelement[adj[a][i]] == 1)
        {
            i++;
        }
        else if (visitedelement[adj[b][j]] == 1)
        {
            j++;
        }
        else
        {
            if (adj[a][i] < adj[b][j])
                return true;
            else if (adj[a][i] > adj[b][j])
                return false;
            else
            {
                i++;
                j++;
            }
        }
        if(i==n) return true;
        if(j==m) return false; 
    }

    return true;
}

const int MAX_VAL = 1000005;
int ap[MAX_VAL];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            vector<int> v(m);
            for(auto &it:v) cin>>it;

            reverse(v.begin(), v.end());
            int mm = v.size();
            for(int it=0;it<mm;it++){
                if(ap[v[it]]==0){
                    adj[i].push_back(v[it]);
                    ap[v[it]]=1;
                }
            }

            for (int x : adj[i]) ap[x] = 0;
            
        }
    


        vector<int> ans;
        vector<int> visitedarr(n, 0);

        for (int k = 0; k < n; k++)
        {
            int curr = -1;
            for (int i = 0; i < n; i++)
            {
                if (visitedarr[i] == 0)
                {
                    //cout<<curr<<"-"<<i<<" ";
                    if (curr==-1 || adj[i]<adj[curr])
                    {
                        curr = i;
                    }
                }
            }
            
            visitedarr[curr] = 1;

            for (int it = 0; it < adj[curr].size(); it++)
            {
                ans.push_back(adj[curr][it]);
                ap[adj[curr][it]]=1;
            }

            adj[curr] = {INT_MAX};

            for(int i=0;i<n;i++){
                if(visitedarr[i]==0){
                    vector<int> temp;
                    for(int x:adj[i]){
                        if(ap[x]==0){
                            temp.push_back(x);
                        }
                    }
                    adj[i] = temp;
                }
            }
        }

        for(int x:ans) cout<<x<<" ";
        cout<<endl;

        for(int x:ans) ap[x] = 0;
    }

    return 0;
}