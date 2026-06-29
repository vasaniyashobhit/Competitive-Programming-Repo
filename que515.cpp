#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    // Fast I/O is mandatory for 2*10^5 constraints
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    if(!(cin >> n)) return 0;

    vector<pair<int,int>> points(n);
    set<pair<int,int>> point_set;

    // 1. Read input and store all valid points in a set for O(log N) lookup
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        point_set.insert(points[i]);
    }

    queue<pair<int,int>> q;
    map<pair<int,int>, pair<int,int>> ans;

    // 2. Find all "boundary" points (excluded points touching included points)
    for (auto p : points) {
        for (int i = 0; i < 4; i++) {
            pair<int,int> neighbor = {p.first + dx[i], p.second + dy[i]};
            
            // If the neighbor is NOT in our set, it is an excluded point
            if (point_set.find(neighbor) == point_set.end()) {
                // If we haven't added this boundary point to our queue yet
                if (ans.find(neighbor) == ans.end()) {
                    ans[neighbor] = neighbor; // A boundary point's nearest excluded point is itself
                    q.push(neighbor);
                }
            }
        }
    }

    // 3. Multi-Source BFS
    while (!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int,int> v = {u.first + dx[i], u.second + dy[i]};
            
            // If v is an included point AND we haven't visited it yet
            if (point_set.find(v) != point_set.end() && ans.find(v) == ans.end()) {
                ans[v] = ans[u]; // Pass the answer down the chain
                q.push(v);
            }
        }
    }

    // 4. Output the answers in the exact order they were given
    for (auto p : points) {
        cout << ans[p].first << " " << ans[p].second << "\n";
    }

    return 0;
}