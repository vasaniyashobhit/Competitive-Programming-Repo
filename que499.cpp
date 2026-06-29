#include<bits/stdc++.h>
using namespace std;

struct Project{
    int start;
    int end;
    int reward;
};

bool compareProjects(const Project& a, const Project& b) {
    return a.start < b.start;
}

int main(){
    
    int n; cin>>n;

    vector<Project> projects(n);
    vector<int> times;
    for(int i=0;i<n;i++){
        cin>>projects[i].start>>projects[i].end>>projects[i].reward;
        times.push_back(projects[i].start);
        times.push_back(projects[i].end);
    }

    sort(projects.begin(), projects.end(), compareProjects);

    sort(times.begin(),times.end());
    vector<int> compressed;
    compressed.push_back(times[0]);
    for(int i=1;i<times.size();i++){
        if(times[i]!=times[i-1]) compressed.push_back(times[i]);
    }

    for(int i=0;i<n;i++){
        projects[i].start = lower_bound(compressed.begin(), compressed.end(), projects[i].start) - compressed.begin() + 1;
        projects[i].end = lower_bound(compressed.begin(), compressed.end(), projects[i].end) - compressed.begin() + 1;
    }

    int maxtime = compressed.size();
    vector<long long> dp(maxtime + 2, 0);

    int ptr = n-1;
    for(int i=maxtime;i>=0;i--){
        dp[i] = dp[i+1];
        
        while(ptr>=0 && projects[ptr].start==i){
            long long reward = projects[ptr].reward;
            int endday = projects[ptr].end;

            dp[i] = max(dp[i],reward+dp[endday+1]);
            ptr--;
        }
    }

    cout<<dp[1]<<endl;
    

    return 0;
}

