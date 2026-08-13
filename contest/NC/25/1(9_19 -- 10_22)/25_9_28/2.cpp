#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    int a;
    int mn = INT_MAX,mx = INT_MIN;
    int mni,mxi;
    for (int i = 0;i < n;i++) 
    {
        cin >> a;
        if (a < mn) 
        {
            mni = i;
            mn = a;
        }
    }
    for (int i = 0;i < n;i++) 
    {
        cin >> a;
        if (a > mx)
        {
            mx = a;
            mxi = i;
        }
    }
    cout << mni + 1 << " " << mxi + 1;
    
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}