#include<iostream>
#include<string>
using namespace std;

int main(){
    
        int n; cin>>n;
        string s; cin>>s;
        char m=s[0];
        pair<int,int> p = {0,-1};
        for(int i=0;i<n;i++){
            if(s[i]>=m){
                m = s[i];
                p.first = i;
            }
            else{
                p.second = i;
                break;
            }
        }
        if(p.second==-1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<(p.first)+1<<" "<<(p.second)+1<<endl;
        }
    

    return 0;
}