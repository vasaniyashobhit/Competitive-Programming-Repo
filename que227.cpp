#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int sum=0;
        vector<int> ans;
        bool k1=false,k2=false;
        for(int i=0;i<n;i++){
            if(s[i]=='(') sum++;
            else sum--;
            if(sum>0){
                k1 = true;
                ans.push_back(1);
            }
            else if(sum==0){
                ans.push_back(ans.back());
            }
            else{
                k2 = true;
                ans.push_back(2);
            } 
        }

        if(sum!=0){
            cout<<-1<<endl;
            continue;
        }
        if(k1==true && k2==true){
            cout<<2<<endl;
            for(auto it:ans) cout<<it<<" ";
            cout<<endl;
        }
        else{
            cout<<1<<endl;
            for(int i=0;i<n;i++) cout<<1<<" ";
            cout<<endl;
        }
    }

    return 0;
}