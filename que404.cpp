#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        if(n==1){
            cout<<1<<endl;
            continue;
        }

        set<int> st;
        for(int it:a) st.insert(it);

        vector<int> b;
        for(auto it:st) b.push_back(it);
        int maxlen=1;
        int len=1;
        int m = b.size();
        
        for(int i=1;i<m;i++){
            if(b[i]==b[i-1]+1){
                len++;
                maxlen = max(maxlen,len);
            }
            else len = 1;
        }

        cout<<maxlen<<endl;
    }

    return 0;
}