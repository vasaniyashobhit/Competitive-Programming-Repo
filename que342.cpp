#include<bits/stdc++.h>
using namespace std;


void check(string &s, string a){
    int n = s.size();
    int m = a.size();

    int i=0,j=0;
    if(m<=n){
        while(j<n){
            if(s[j]<a[i]){
                s = s+a;
                return;
            }
            if(s[j]>a[i]) break;
            i++;
            j++;
            i%=m;
        }
        s = a+s;
        return;
    }
    else{
        while(i<m){
            if(s[j]<a[i]){
                s = s+a;
                return;
            }
            if(s[j]>a[i]) break;
            i++;
            j++;
            j%=n;
        }
        s = a+s;
        return;
    }
    return ;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }

        string s;
        if((a[0]+a[1])<=(a[1]+a[0])){
            s = a[0]+a[1];
        }
        else{
            s = a[1]+a[0];
        }


        if(n==2){
            cout<<s<<endl;
            continue;
        }

        for(int i=2;i<n;i++){
            check(s,a[i]);
        }
        cout<<s<<endl;
    }

    return 0;
}