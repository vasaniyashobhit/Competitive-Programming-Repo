#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    string fans = "";
    while(t--){
        string s; cin>>s;
        long long pos; cin>>pos;
        long long n = s.size();
        stack<char> st;
        long long currs=s.size();
        long long i=0;
        while(true){
            if(pos<=currs){

            }
            else{
                // ith element
                if(i<=n-1){
                    while(i<n && s[i]<=s[i+1]){
                        st.push(s[i]);
                        i++;
                    }
                    
                }
                else{
                    // delete from stack
                    st.pop();
                }

            }
        }
    }
}