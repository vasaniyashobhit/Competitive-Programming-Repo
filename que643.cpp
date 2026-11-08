#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int diff, int n, int m, vector<vector<int>> &b, vector<int> &a,
           vector<int> &cnt, vector<int> &stamp, int stampId){
    int distinct = 0;
    int l = 0, r = 0;
    auto add = [&](int t){
        if (stamp[t] != stampId) { stamp[t] = stampId; cnt[t] = 0; }
        if (cnt[t] == 0) distinct++;
        cnt[t]++;
    };
    auto remove_ = [&](int t){
        cnt[t]--;
        if (cnt[t] == 0) distinct--;
    };

    for (int it : b[0]) add(it);
    if (distinct == m) return true;

    while (r + 1 < n) {
        r++;
        for (int it : b[r]) add(it);
        while (l < r && a[r] - a[l] > diff) {
            for (int it : b[l]) remove_(it);
            l++;
        }
        if (distinct == m) return true;
    }
    return false;
}

void solve() {
    int nn, m; cin >> nn >> m;
    vector<int> aa(nn);
    for (int &it : aa) cin >> it;
    sort(aa.begin(), aa.end());

    vector<int> a;
    a.push_back(aa[0]);
    for (int i = 1; i < nn; i++) if (aa[i] != aa[i-1]) a.push_back(aa[i]);
    int n = a.size();

    vector<vector<int>> b(n);
    for (int i = 0; i < n; i++) {
        b[i].push_back(1);
        if (a[i] <= m && a[i] != 1) b[i].push_back(a[i]);
        for (int j = 2; j*j <= a[i]; j++) {
            if (a[i] % j != 0) continue;
            int num1 = j, num2 = a[i]/j;
            if (num1 <= m) b[i].push_back(num1);
            if (num2 <= m && num1 != num2) b[i].push_back(num2);
        }
    }

    static vector<int> cnt, stamp;
    static int stampId = 0;
    if ((int)cnt.size() < m + 1) { cnt.assign(m+1, 0); stamp.assign(m+1, 0); }

    int l = 0, r = a[n-1] - a[0];
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        stampId++;
        if (check(mid, n, m, b, a, cnt, stamp, stampId)) { ans = mid; r = mid - 1; }
        else l = mid + 1;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}