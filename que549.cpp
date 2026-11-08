#include<bits/stdc++.h>
using namespace std;

using ll = long long;

string num = "12345";

const int N = 5;
const int MAXSUM = 200;
int dp[N][2][MAXSUM];

int SUM = 15;

// question: find no. of numbers which is less than 12345 and sum of its digits is 15

int f(int index,int tight, int sumMadeYet){  // tight = 1 -> tightbound  // tight = 0 free
    if(sumMadeYet>SUM) return 0;
    
    if(index == num.size()){
        if(sumMadeYet==SUM){
            return 1;
        }
        else return 0;
    }

    if(dp[index][tight][sumMadeYet] != -1) return dp[index][tight][sumMadeYet]; 

    int bound = (tight==1) ? num[index]-'0' : 9  ;

    int sum = 0;

    for(int i=0;i<=bound;i++){
        if(i==bound && tight==1) sum += f(index+1,1,sumMadeYet+i);
        else sum += f(index+1,0,sumMadeYet+i);
    }

    return dp[index][tight][sumMadeYet] = sum;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cout<<f(0,1,0)<<endl;

    return 0;
}