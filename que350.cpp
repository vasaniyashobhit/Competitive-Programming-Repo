#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    if(s=="first"){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        string output="";
        for(int i=0;i<n;i++){
            output += char(96+a[i]);
        }
        cout<<output<<endl;
    }
    else{
        string output; cin>>output;
        vector<int> ans;
        for(int i=0;i<output.size();i++){
            ans.push_back(output[i]-'a'+1);
        }
        cout<<output.size()<<endl;
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}