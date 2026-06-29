#include<bits/stdc++.h>
using namespace std;

bool check(string ss,string s,int size){
    bool ans = false;
    if(size==1){
        for(int i=0;i<s.size();i++){
            if(s[i]==ss[0]){
                return false;
            }
        }
    }
    else if(size==2){
        for(int i=0;i<s.size()-1;i++){
            if(ss[0]==s[i] && ss[1]==s[i+1]){
                return false;
            }
        }
    }
    else{
        for(int i=0;i<s.size()-2;i++){
            if(ss[0]==s[i] && ss[1]==s[i+1] && ss[2]==s[i+2]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        bool k = false;
        for(char c='a';c<='z';c++){
            string ss(1,c);
            if(check(ss,s,1)){
                k = true;
                cout<<c<<endl;
                break;
            }
        }

        if(k==false){
            for(char c='a';c<='z';c++){
                for(char d='a';d<='z';d++){
                    string ss(2,'a');
                    ss[0] = c;
                    ss[1] = d;
                    if(check(ss,s,2)){
                        k = true;
                        cout<<ss<<endl;
                        break;
                    }
                }
                if(k==true) break;
            }
        }

        if(k==false){
            for(int i='a';i<='z';i++){
                for(int j='a';j<='z';j++){
                    for(int h='a';h<='z';h++){
                        string ss(3,'a');
                        ss[0]=i;
                        ss[1]=j;
                        ss[2]=h;
                        if(check(ss,s,3)){
                            cout<<ss<<endl;
                            k=true;
                            break;
                        }
                    }
                    if(k==true) break;
                }
                if(k==true) break;
            }
        }
    }

    return 0;
}