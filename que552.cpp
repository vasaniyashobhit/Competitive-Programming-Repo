#include<bits/stdc++.h>
using namespace std;

int ask(int ind1, int ind2){
    string s = "? ";
    s += to_string(ind1);
    s += " ";
    s += to_string(ind2);
    cout<<s<<endl;
    int x; cin>>x;
    return x;
}

int main(){
    int n; cin>>n;

    if(n==1){
        cout<<"! "<<1<<endl;
        return 0;
    }
    queue<int> q;
    vector<int> ans(n+1,-1);
    for(int i=1;i<=n;i++) q.push(i);

    for(int i=1;i<n;i++){
        int a1 = q.front();
        q.pop();
        int a2 = q.front();
        q.pop();

        int x = ask(a1,a2);
        int y = ask(a2,a1); 

        if(x>y){
            ans[a1] = x;
            q.push(a2);
        }
        else{
            ans[a2] = y;
            q.push(a1);
        }
    }
    int lst = q.front();
    ans[lst] = n;

    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}