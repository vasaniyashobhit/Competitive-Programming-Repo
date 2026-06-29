#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        
        vector<pair<int,int>> suff(n,{0,0});
        suff[n-1] = {0,1};
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1];
            if(s[i]=='(') suff[i].first++;
            else suff[i].second++;
        }
        
        bool ans = false;
        int sum = 0;
        int maxans = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='(') sum++;
            else sum--;

            if(s[i]==')'){
                int sum1 = sum+2;
                if(suff[i+1].second>=sum1){
                    ans = true;
                    int fans = i+1+sum1;
                    fans += 2*min(suff[i+1].first-1,suff[i+1].second-sum1);
                    maxans = max(maxans,fans);
                }
            }
        }
        if(ans==true) cout<<maxans<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}