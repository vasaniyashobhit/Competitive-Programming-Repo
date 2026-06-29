#include<iostream>
#include<vector>
using namespace std;

void ask(int l, int r){
    string s = "? ";
    s += to_string(l) + ' ';
    s += to_string(r);
    cout<<s<<endl;
}

int main(){
    int n; cin>>n;
    
    ask(1,n);
    int p; cin>>p;

    // right side
    int s = p+1,e=n;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        ask(p,mid);
        int ind; cin>>ind;
        if(ind==p){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    if(ans!=-1 && ans!=p){
        string fans = "! " + to_string(ans);
        cout<<fans<<endl;
        return 0;
    }

    // left;
    s = 1,e=p-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        ask(mid,p);
        int ind; cin>>ind;
        if(ind==p){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    string fans = "! " + to_string(ans);
    cout<<fans<<endl;

    return 0;
}