#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,x,y; cin>>n>>x>>y;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> b;
    queue<int> q;
    int sm = 1e6;
    for(int i=0;i<n;i++){
        if(i<=x-1 || i>=y) b.push_back(a[i]);
        else{
            q.push(a[i]);
            sm = min(sm,a[i]);
        }
    }

    while(q.front() != sm){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

    if(b.size()==0){
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
        return;
    }

    vector<int> ans;
    for(int i=0;i<b.size();i++){
        if(q.front()>b[i]){
            ans.push_back(b[i]);
        }
        else{
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                ans.push_back(temp);
            }
            while(i<b.size()) ans.push_back(b[i++]);
        }
    }

    if(!q.empty()){
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
        }
    }

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

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