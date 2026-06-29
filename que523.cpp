#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int maxlen = 1;
    int len = 1;
    for(int i=0;i<s.size();i++){
        if(s[i]==s[i-1]){
            len++;
            maxlen = max(len,maxlen);
        }
        else{
            len = 1;
        }
    }
    cout<<maxlen<<endl;


    return 0;
}