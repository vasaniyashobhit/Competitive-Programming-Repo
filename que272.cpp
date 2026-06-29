#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();

        if(n==1){
            cout<<1<<endl;
            continue;
        }

        bool inf = false;
        for(int i=0;i<n-1;i++){
            if(s[i]=='*' && s[i+1]=='*') inf=true;
            if(s[i]=='>' && s[i+1]=='*') inf=true;
            if(s[i]=='*' && s[i+1]=='<') inf=true;
            if(s[i]=='>' && s[i+1]=='<') inf=true;
        }

        if(inf==true){
            cout<<-1<<endl;
            continue;
        }

        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='>')break;
            ans1++;   
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='<') break;
            ans2++;
        }

        cout<<max(ans1,ans2)<<endl;
    }

    return 0;
}


1->2->3->4->5
null

// ans should be = newnode->1->2->3->4->5

1 head node

ptr = head;
if(head==null){
    cout<<"list is empty";
    return; // exit
}
else{
    node *newnode(enull);
    newnode->next = ptr;
}



        
