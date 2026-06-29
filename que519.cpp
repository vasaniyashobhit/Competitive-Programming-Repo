#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        vector<int> rep;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) rep.push_back(i);
        }

        long long ans = 0;

        for(int i=0;i<n;i++){
            auto j = upper_bound(rep.begin(),rep.end(),i);
            int indj = j-rep.begin();
            char k = s[i];
            if(j!=rep.end()) ans++;
            while(j != rep.end()){
                cout<<"hello"<<" ";
                if(s[indj+1]==k){
                    j = upper_bound(rep.begin(),rep.end(),indj+1);
                    int newind = j-rep.begin();
                    ans += newind-indj-1;
                    indj = newind;
                    k = s[newind-1];
                }
                else{
                    j = upper_bound(rep.begin(),rep.end(),indj);
                    if(j!=rep.end()) ans++;
                    indj = j-rep.begin();
                    if(k=='1') k = '0';
                    else k = '1';
                }

            }
        }
        cout<<ans+n<<endl;
    }

    return 0;
}