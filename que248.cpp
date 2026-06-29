#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,c,d; cin>>a>>b>>c>>d;
    double numerator = a*d;
    double denominator = a*d + b*c - a*c;
    cout<<setprecision(12)<<(numerator/denominator)<<endl;
    
    return 0;
}