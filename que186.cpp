#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(a[i]);
        }
        if(st.size()==n) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}