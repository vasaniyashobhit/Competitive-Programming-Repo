#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        vector<int> a(n);
        vector<int> b(m);
        for(int &it:a) cin>>it;
        for(int &it:b) cin>>it;
        string s; cin>>s;
        sort(b.begin(),b.end());
        sort(a.begin(),a.end());

        vector<int> curr(k);
        int c = 0;
        for(int i=0;i<k;i++){
            if(s[i]=='L') c-=1;
            else c+=1;

            curr[i] = c;
        }
        map<int,int> mp;
        for(int i=0;i<k;i++){
            if(mp.find(curr[i])==mp.end()) mp[curr[i]] = i;
        }

        vector<int> diffans(k,0);
        for(int i = 0;i<n;i++){
            int pos = a[i];
            int right;
            int left;
            if(pos<b[0]){
                right = b[0]-pos;
                left = k+1;
            }
            else if(pos>b[m-1]){
                right = k+1;
                left = b[m-1]-pos;
            }
            else{
                auto it = lower_bound(b.begin(),b.end(),pos);
                right = (*it)-pos;
                --it;
                left = (*it)-pos;
            }

            int m1,m2;  // m1-left   m2-right
            if(mp.find(left)==mp.end()) m1=k+1;
            else m1 = mp[left];

            if(mp.find(right)==mp.end()) m2 = k+1;
            else m2 = mp[right];

            int mini = min(m1,m2);
            if(mini<k) diffans[mini]--;
        }
        int count = n;
        for(int i=0;i<k;i++){
            count += diffans[i];
            cout<<count<<" ";
        }
        cout<<endl;

    }

    return 0;
}

 