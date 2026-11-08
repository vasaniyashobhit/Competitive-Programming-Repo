#include<bits/stdc++.h>
using namespace std;

int counter = 0;

void simulate(int ind, int mask, int n, string s){
    if(ind==n){
        cout<<s<<endl;
        counter++;
        return;
    }

    for(int i=0;i<n;i++){
        if(((mask>>i)&1)==0){
            simulate(ind+1,mask|(1<<i),n,s+" "+to_string(i+1));
        }
    }
    
    return;
}

int main(){
    vector<int> a = {1,2,3,4};
    int mask=0;
    string s="";
    simulate(0,mask,4,s);
    cout<<counter<<endl;

    return 0;
}