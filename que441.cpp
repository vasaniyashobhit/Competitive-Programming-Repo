#include<bits/stdc++.h>
using namespace std;

int main(){
    
    
        int n; cin>>n;
        vector<pair<int,int>> a(n);
        vector<pair<int,int>> b(n);

        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
            b[i].first = a[i].first;
            b[i].second = a[i].second;
        }

        //sort(a.begin(),a.end());
        sort(a.begin(), a.end(), [](const pair<int, int>& a1, const pair<int, int>& b1) {
        // If first elements are not equal, sort them in ascending order
        if (a1.first != b1.first) {
            return a1.first < b1.first;
        }
        // If first elements are equal, sort second elements in descending order
        return a1.second > b1.second;
    });
        vector<int> s(n,0);
        s[n-1] = a[n-1].second;
        for(int i=n-2;i>=0;i--){
            s[i] = min(s[i+1],a[i].second);
        }
        pair<int,int> p={-1,-1};
        int m=a[0].second;
        for(int i=0;i<n-1;i++){
            m = max(m,a[i].second);
            if(m>=s[i+1]){
                p = a[i];
                break;
            }
        }
        if(p.first==-1){
            cout<<-1<<" "<<-1<<endl;
            return 0;
        }
        int cnt = 0;
        pair<int,int> ans;
        for(int i=0;i<n;i++){
            if(b[i]==p) cnt++;
        }
        if(cnt>=2){
            vector<int> ans1;
            for(int i=0;i<n;i++){
                if(b[i]==p) ans1.push_back(i);
            }
            cout<<ans1[0]+1<<" "<<ans1[1]+1<<endl;
        }
        else{
            //cout<<p.first<<" "<<p.second<<endl;
            for(int i=0;i<n;i++){
                if(b[i]==p) ans.second = i;
                else if(b[i].first>=p.first && b[i].second<=p.second) ans.first = i;
            }
            //cout<<"hello"<<endl;
            cout<<ans.first+1<<" "<<ans.second+1<<endl;
        }
    

    return 0;
}