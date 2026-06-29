#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;


        bool k = false;
        for(int i=1;i<n;i++){
            if(s[i-1]=='1' && s[i]=='0'){
                k = true;
                break;
            }
        }

        if(k==true){
            cout<<"Alice"<<endl;
            vector<int> pref1(n,0);
            vector<int> suff0(n,0);
            if(s[0]=='1') pref1[0] = 1;
            if(s[n-1]=='0') suff0[n-1] = 1;

            for(int i=1;i<n;i++){
                pref1[i] = pref1[i-1];
                if(s[i]=='1') pref1[i]++;
            }
            for(int i=n-2;i>=0;i--){
                suff0[i] = suff0[i+1];
                if(s[i]=='0') suff0[i]++;
            }

            vector<int> ans;
            int ind = 0;
            for(int i=0;i<n-1;i++){
                if(s[i]=='1') ans.push_back(i+1);
                if(pref1[i]==suff0[i+1]){
                    ind = i+1;
                    break;
                }
            }
            for(int i=ind;i<n;i++){
                if(s[i]=='0') ans.push_back(i+1);
            }

            cout<<ans.size()<<endl;
            for(int it:ans) cout<<it<<" ";
            cout<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
}