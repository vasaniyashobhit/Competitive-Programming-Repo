#include<bits/stdc++.h>
using namespace std;

bool insert(long long a,long long b, long long c, map<pair<long long,long long>,long long> &mp, map<long long, long long> &startend,map<long long, long long> &endstart){
    if(mp.find({a,b})!=mp.end()){
        if(c!=mp[{a,b}]) return false;
        return true;
    }    

    if(startend.find(a)!=startend.end()){
        pair<long long, long long> present = {a,startend[a]};
        long long presentcost = mp[present];
        if(present.second>b){
            mp.erase(present);
            startend.erase(present.first);
            startend.erase(present.second);
            pair<long long, long long> newp = {b+1,present.second};
            long long newpcost = presentcost - c;
            bool k = insert(newp.first,newp.second,newpcost,mp,startend,endstart);
            if(k==false) return false;
            bool k = insert(a,b,c,mp,startend,endstart);
            if(k==false) return false;
        }
        else{
            bool k = insert(present.second+1,b,c-presentcost,mp,startend,endstart);
            if(k==false) return false;
        }
    }
    else if(endstart.find(b)!=endstart.end()){
        pair<long long, long long> present = {endstart[b],b};
        long long presentcost = mp[present];
        if(present.first<a){
            mp.erase(present);
            startend.erase(present.first);
            endstart.erase(present.second);
            bool k = insert(a,b,c,mp,startend,endstart);
        }
        else{
            bool k = insert(a,present.first-1,c-presentcost,mp,startend,endstart);
            if(k==false) return false;
        }
    }
    else{
        startend[a] = b;
        endstart[b] = a;
        mp[{a,b}] = c;
    }

    return true;
}

int main(){
    long long n,m; cin>>n>>m;
    vector<vector<int>> cond(m,vector<int> (3,-1));
    map<pair<long long,long long>,long long> mp;
    map<long long, long long> startend;
    map<long long, long long> endstart;
    bool k = true;
    for(long long i=0;i<m;i++){
        long long a,b,c; cin>>a>>b>>c;
        cond[i][0] = a; cond[i][1] = b; cond[i][2] = c;
        k = insert(a,b,c,mp,startend,endstart); 
        if(k==false){
            break;
        }  
    }
    if(k==false) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}