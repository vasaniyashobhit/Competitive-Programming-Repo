#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k,x; cin>>n>>k>>x;
        long long ans2 = k;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;
        sort(a.begin(),a.end());

        set<pair<long long,pair<long long,long long>>> gaps;
        for(long long i=1;i<n;i++){
            gaps.insert({a[i]-a[i-1],{a[i-1]+1,a[i]-1}});
        }
        pair<long long,pair<long long,long long>> right = {a[0]-0,{0,a[0]-1}};
        pair<long long,pair<long long,long long>> left = {x-a[n-1],{a[n-1]+1,x}};

        bool kk = true;
        vector<long long> ans;
        while(k>0){
            pair<long long,pair<long long,long long>> p = *(gaps.rbegin());
            if(p.first==0 && right.first==0 && left.first==0){
                kk = false;
                break;
            }
            
            if(right.first>=p.first){
                ans.push_back(right.second.first);
                right.first--;
                right.second.first++;
                k--;
                continue;
            }
            else if(left.first>=p.first){
                ans.push_back(left.second.second);
                left.first--;
                left.second.second--;
                k--;
                continue;
            }
            // if(p.second.first==0){
            //     pair<int,pair<int,int>>p1 = {p.first-1 , {1 , p.second.second}};
            //     gaps.erase(*(gaps.rbegin()));
            //     gaps.insert(p1);
            //     k--;
            //     ans.push_back(0);
            //     continue;
            // }
            // else if(p.second.second==x){
            //     pair<int,pair<int,int>>p1 = {p.first-1 , {p.second.first , x-1}};
            //     gaps.erase(*(gaps.rbegin()));
            //     gaps.insert(p1);
            //     k--;
            //     ans.push_back(x);
            //     continue;
            // }

            long long ind = (p.second.first+p.second.second)/2;
            ans.push_back(ind);
            pair<long long,pair<long long,long long>> p1 = {ind-p.second.first , {p.second.first , ind-1} };
            pair<long long,pair<long long,long long>> p2 = {p.second.second-ind , {ind+1 , p.second.second} };
            gaps.erase(*(gaps.rbegin()));
            gaps.insert(p1);
            gaps.insert(p2);
            k--;
        }

        if(kk==true){
            for(auto it:ans) cout<<it<<" ";
            cout<<endl;
        }
        else{
            for(int i=0;i<ans2;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }


    return 0;
}