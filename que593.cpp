#include<bits/stdc++.h>
using namespace std;

const int LOG = 20; // Renamed to avoid namespace collision

// Added edge_wt to pass the weight of the incoming edge
void dfs(int node, int parent, int edge_wt, vector<vector<pair<int,int>>> &adj, vector<vector<pair<int,int>>> &dp, vector<int> &dep)
{
    if (parent == -1) dep[node] = 0;
    else dep[node] = dep[parent] + 1;
    
    // Base case for binary lifting: the 2^0 (1st) ancestor is the direct parent
    dp[node][0].first = parent;
    dp[node][0].second = edge_wt; 
    
    for(int i = 0; i < adj[node].size(); i++)
    {
        int v = adj[node][i].first;
        int w = adj[node][i].second;
        
        if(v == parent) continue;
        dfs(v, node, w, adj, dp, dep);
    }
}

void calclca(int n, vector<vector<pair<int,int>>> &dp)
{
    // Outer loop MUST be j (powers of 2) to build state correctly
    for(int j = 1; j < LOG; j++)
    {
        for(int i = 0; i < n; i++)
        {
            int intermediate_node = dp[i][j-1].first;
            
            // Protect against out-of-bounds if ancestor doesn't exist
            if (intermediate_node != -1) {
                dp[i][j].first = dp[intermediate_node][j-1].first;
                dp[i][j].second = min(dp[i][j-1].second, dp[intermediate_node][j-1].second); 
            } else {
                dp[i][j].first = -1;
                dp[i][j].second = 2e9; 
            }
        }
    }
}

int findlca(int u, int v, vector<vector<pair<int,int>>> &dp, vector<int> &dep)
{
    int minans = 2e9; // Start with infinity
    
    // Swap the NODES based on depth, not just the depth integers
    if(dep[u] < dep[v]) swap(u, v); 
    
    int diff = dep[u] - dep[v];
    
    // 1. Equalize depths
    for(int i = 0; i < LOG; i++)
    {
        // Use the difference directly
        if((diff >> i) & 1) 
        {
            minans = min(minans, dp[u][i].second);
            u = dp[u][i].first; // Correctly extract the node integer
        }
    }
    
    // If equalizing depths made them meet, v was an ancestor of u
    if(u == v) return minans; 
    
    // 2. Jump together (MUST iterate backwards!)
    for(int i = LOG - 1; i >= 0; i--)
    {
        if(dp[u][i].first != dp[v][i].first)
        {
            minans = min(minans, dp[u][i].second);
            minans = min(minans, dp[v][i].second);
            u = dp[u][i].first;
            v = dp[v][i].first;
        }
    }    
    
    // 3. One final jump to hit the actual LCA
    minans = min(minans, dp[u][0].second);
    minans = min(minans, dp[v][0].second);
    
    return minans;
}

void solve()
{
    int n, m; cin >> n >> m;
    
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        u--; v--; // Using 0-based indexing
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dep(n, 0);
    // Initialize DP table to -1 for ancestors and high value for minimums
    vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(LOG, {-1, 2e9}));

    // Passing 2e9 as the dummy weight above the root
    dfs(0, -1, 2e9, adj, dp, dep);
    
    calclca(n, dp);
    
    int q; cin >> q;
    while(q--)    {
        int a, b; cin >> a >> b;
        a--; b--;
        int ans = findlca(a, b, dp, dep);
        cout << ans << "\n";
    }
}

int main()
{
    // Fast I/O for CP 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while(t--) solve();

    return 0;
}