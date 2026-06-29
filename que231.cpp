#include <iostream>
#include<algorithm>
using namespace std;

int helper(int mid,int a,int b,int n){
        int count = 0;
        count += mid/a;
        count += mid/b;
        int c = a*b/__gcd(a,b);
        count -= mid/c;
        return count;
    }

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int l = 2, r = 100;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int cnt = helper(mid, a, b, n);
        cout<<mid<<"-"<<cnt<<" ";
        if (cnt == n)
        {
            ans = mid;
            r = mid-1;
        }
        else if (cnt < n)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if ((ans % a != 0) && (ans % b != 0))
    {
        int ans1 = ans - (ans % a);
        int ans2 = ans - (ans % b);
        ans = max(ans1, ans2);
    }
    cout<<endl;
    cout<<ans<<endl;

    return 0;
}