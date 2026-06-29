#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(long long &it : a) cin >> it;

    set<long long> st;
    map<long long, long long> mp;
    long long count = 0;
    long long l = 0, r = -1;
    long long maxi = 0, mini = 0;

    while(l < n){
        // The condition checks the state of the set BEFORE adding the next element
        while(st.empty() || (r + 1 < n && (*st.rbegin() - *st.begin() <= k))){
            r++;
            mp[a[r]]++;         // BUG 1 FIX: Use a[r] as key and just increment
            if (mp[a[r]] == 1) { // Only insert into set if it's the first time
                st.insert(a[r]);
            }
        }

        // For this `l`, the valid right endpoints are l...r. Number of segments is r - l + 1.
        if (r >= l) {
            count += (r - l + 1);
        }

        // Shrink window from the left
        mp[a[l]]--;
        if(mp[a[l]] == 0){
            st.erase(a[l]);
        }
        l++;
    }

    cout << count << endl;

    return 0;
}