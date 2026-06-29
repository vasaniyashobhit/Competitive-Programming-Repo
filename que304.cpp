#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        
        string set="";
        vector<int> a(1000,0);
        for(int i=0;i<n;i++){
            if(a[s[i]-'a']==1) break;
            set += s[i];
            a[s[i]-'a']=1;
        }

        bool k = true;
        int j=0,n2=set.size();
        for(int i=0;i<n;i++){
            if(s[i]!=set[j]){
                k = false;
                break;
            }
            j++;
            j %= n2;
        }

        if(k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}