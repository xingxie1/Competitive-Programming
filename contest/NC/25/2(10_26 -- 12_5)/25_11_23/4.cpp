#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int mod = 998244353;
long long fast_pow (long long a,long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void solve()
{
    long long n,k,x,sum = 0;
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        cin >> x;
        if (i % 2) 
        {
            while (x--)
            {
                k = 1LL * k << 1 % mod;
            }
        }
        else 
        {
            while (x--)
            {
                k = 1LL * k >> 1 % mod;
            }
        }
    }
    cout << k << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}