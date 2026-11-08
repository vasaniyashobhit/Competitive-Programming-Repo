#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    bool oddfixed = false;
    bool evenfixed = false;

    for(int i=0;i<n;i++){
        if(i%2==0 && s[i]!='?') evenfixed = true;
        if(i%2!=0 && s[i]!='?') oddfixed = true;
    }

    if(oddfixed == false && evenfixed == false){
        cout<<4<<endl;
        return;
    }

    bool evenpossible = true;
    bool oddpossible = true;
    if(evenfixed == true){
        int ind1 = -1;
        for(int i=0;i<n;i+=2){
            if(s[i] != '?'){
                ind1 = i;
                break;
            }
        }

        for(int i=ind1+2;i<n;i+=2){
            if(s[i]=='?'){
                if(s[i-2]=='1') s[i]='0';
                else s[i] = '1';
            } 
            else if(s[i]==s[i-2]) evenpossible = false;
        }

        for(int i=ind1-2;i>=0;i-=2){
            if(s[i]=='?'){
                if(s[i+1]=='1') s[i] = '0';
                else s[i] = '1';
            }
            else if(s[i]==s[i+2]) evenpossible = false;
        }
    }

    if(oddfixed == true){
        int ind2 = -1;
        for(int i=1;i<n;i+=2){
            if(s[i] != '?'){
                ind2 = i;
                break;
            }
        }

        for(int i=ind2+2;i<n;i+=2){
            if(s[i]=='?'){
                if(s[i-2]=='1') s[i]='0';
                else s[i] = '1';
            } 
            else if(s[i]==s[i-2]) oddpossible = false;
        }

        for(int i=ind2-2;i>=0;i-=2){
            if(s[i]=='?'){
                if(s[i+1]=='1') s[i] = '0';
                else s[i] = '1';
            }
            else if(s[i]==s[i+2]) oddpossible = false;
        }

    }

    if(evenfixed==true && evenpossible==false){
        cout<<0<<endl;
        return;
    }
    if(oddfixed==true && oddpossible==false){
        cout<<0<<endl;
        return;
    }

    if(evenfixed==false && oddfixed==false){
        cout<<4<<endl;
        return;
    }
    else if(evenfixed==true && oddfixed==false){
        cout<<2<<endl;
        return;
    }
    else if(evenfixed==false && oddfixed==true){
        cout<<2<<endl;
        return;
    }
    else cout<<1<<endl;

    return;


}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}