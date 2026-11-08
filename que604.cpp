#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long long merge(std::vector<int>& arr, int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    long long count = 0;
    std::vector<int> t(r - l + 1);
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) t[k++] = arr[i++];
        else { t[k++] = arr[j++]; count += (m - i + 1); }
    }
    while (i <= m) t[k++] = arr[i++];
    while (j <= r) t[k++] = arr[j++];
    for (i = l, k = 0; i <= r; i++, k++) arr[i] = t[k];
    return count;
}

long long countInv(std::vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    return countInv(arr, l, m) + countInv(arr, m + 1, r) + merge(arr, l, m, r);
}

long long getInversionCount(std::vector<int> arr) {
    if (arr.empty()) return 0;
    return countInv(arr, 0, arr.size() - 1);
}

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int &it:a) cin>>it;
    for(int &it:b) cin>>it;

    vector<int> c = a;
    vector<int> d = b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());

    int inva = getInversionCount(a);
    int invb = getInversionCount(b);

    if(((inva %2==0 && invb%2==0) || (inva%2!=0 && invb%2!=0)) && c==d) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}