#include<iostream>
#include<string>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') sum++;
            else sum--;

            if(sum<0){
                cnt++;
                sum = 0;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}