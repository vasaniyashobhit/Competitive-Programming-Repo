#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long a,n; cin>>a>>n;
        vector<int> d(10,0);
        for(int i=0;i<n;i++){
            int x; cin>>x;
            d[x] = 1;
        }

        string s = to_string(a);
        long long digits = s.size();
        long long ind=-1;
        long long ans = 0;
        for(int i=0;i<digits;i++){
            if(d[s[i]-'0']==0){
                ind = i;
                break;
            }
            ans = ans*10 + (s[i]-'0');
        }
        if(ind==-1){
            cout<<0<<endl;
            continue;
        }
        int bit = s[ind]-'0';
        cout<<ind<<" "<<bit<<endl;
        // b>a
        long long ans2 = ans;
        for(int i=0;i<=9;i++){
            if(d[i]==1 && i>bit){
                ans2 = ans2*10 + i;
                break;
            }
        }
        for(int i=0;i<9;i++){
            if(d[i]==1){
                for(int i = ind+1; i<digits;i++){
                    ans2 = ans2*10 + i;
                }
                break;
            }
        }
        long long fans = abs(a-ans2);

        // b<a
        long long ans3 = ans;
        for(int i=0;i<=9;i++){
            if(d[i]==1 && i<bit){
                ans3 = ans3*10 + i;
                break;
            }
        }
        for(int i=9;i>=0;i--){
            if(d[i]==1){
                for(int i=ind+1;i<digits;i++){
                    ans3 = ans3*10+i;
                }

                break;
            }
        }

        fans = min(fans,abs(a-ans3));
        cout<<fans<<endl;
    }

    return 0;
}