#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int MOD = 998244353;
void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    long long res = 1,ans = 0;
    int l = 0,r = 0;
    while (r < n)
    {
        res = 1;
        if (a[r] == 0)
        {
            l = r + 1;
        }
        else if (r - l + 1 == k)
        {
            if (r == n - 1) 
            {
                for (int i = l;i <= r;i++) 
                {
                    res *= a[i];
                    res %= MOD;
                }
                ans = max(ans,res);
            }
            else if (a[l] > a[r + 1])
            {
                for (int i = l;i <= r;i++) 
                {
                    res *= a[i];
                    res %= MOD;
                }
                ans = max(ans,res);
            }
            l++;
        }
        r++;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}


