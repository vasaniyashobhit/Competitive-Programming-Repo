#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }

    bool k = false;
    for(int i=1;i<2*n;i++){
        if(a[0]!=a[i]){
            k = true;
            break;
        }
    }

    if(k){
        sort(a.begin(),a.end());
        for(int i=0;i<2*n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}