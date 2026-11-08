#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    vector<int> printed(n+1,0);
    stack<int> st;

    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            st.push(i+1);
        }
        else if(s[i]=='2'){
            if(st.empty()){
                printed[i+1] = 1;
            }
            else{
                int x = st.top();
                printed[x] = 1;
                st.pop();
            }
        }
        else{
            printed[i+1] = 1;
        }
    }

    int cnt = 0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(printed[i]==0){
            cnt++;
            ans.push_back(i);
        }
    }

    cout<<cnt<<endl;
    for(int it:ans) cout<<it<<" ";
    cout<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}