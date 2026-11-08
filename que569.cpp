#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    int i=0,j=n-1;
    int x=-1,y=-1;
    while(i<j){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            x = a[i];
            y = a[j]; 
            break;
        }
    }

    if(x==-1){
        cout<<"YES"<<endl;
        return;
    }

    i=0,j=n-1;
    bool k1 = true;
    while(i<j){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            if(a[i]==x) i++;
            else if(a[j]==x) j--;
            else{
                k1 = false;
                break;
            }
        }
    }

    bool k2 = true;
    i=0,j=n-1;
    while(i<j){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            if(a[i]==y) i++;
            else if(a[j]==y) j--;
            else{
                k2 = false;
                break;
            }
        }
    }

    if(k1==true || k2==true){
        cout<<"YES"<<endl;
    }
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