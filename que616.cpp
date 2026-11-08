#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> getNthPermutationSTL(std::vector<int> arr, int n) {
    std::sort(arr.begin(), arr.end());
    
    for (int i = 1; i < n; ++i) {
        if (!std::next_permutation(arr.begin(), arr.end())) {
            break; 
        }
    }
    return arr;
}

void solve() {
    int n,j,k; cin>>n>>j>>k;
    vector<int> a;
    int temp = n;
    while(temp>0){
        int dig = temp%10;
        a.push_back(dig);
        temp /= 10;
    }
    reverse(a.begin(),a.end());

    vector<int> p1 = getNthPermutationSTL(a,j);
    vector<int> p2 = getNthPermutationSTL(a,k);

    int cnta = 0;
    int cntb = 0;
    for(int i=0;i<a.size();i++){
        if(p1[i]==p2[i]) cnta++;
        for(int j=0;j<a.size();j++){
            if(j==i) continue;
            if(p1[i]==p2[j]) cntb++;
        }
    }

    string ans = "";
    ans += to_string(cnta) + "A" + to_string(cntb) + "B";
    cout<<ans<<endl;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}