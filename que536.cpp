#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        vector<long long> neg;
        vector<long long> pos;

        for(int i=0;i<n;i++){
            if(a[i]<=0) neg.push_back(a[i]);
            else pos.push_back(a[i]);
        }

        if(pos.size()==0){
            cout<<"No"<<endl;
            continue;
        }
        else cout<<"Yes"<<endl;

        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end(),greater<int>());

        vector<int> ans;
        int k = pos[pos.size()-1] - neg[neg.size()-1];
        int sum = 0;
        int i=0,j=0;
        while(i<pos.size() && j<neg.size()){
            if(sum+pos[i]<k){
                sum += pos[i];
                ans.push_back(pos[i]);
                i++;
            }
            else{
                sum += neg[j];
                ans.push_back(neg[j]);
                j++;
            }
        }
        while(i<pos.size()){
            ans.push_back(pos[i]);
            i++;
        }
        while(j<neg.size()){
            ans.push_back(neg[j]);
            j++;
        }

        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }
    
    return 0;
}