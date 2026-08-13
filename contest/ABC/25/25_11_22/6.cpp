#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int mod = 998244353;
static const int N = 1000000 + 5;

long long fac[N], inv[N];
long long comb(int n,int k)
{
    if (k < 0 || k > n) return 0;
    return (fac[n] * inv[k] % mod * inv[n - k] % mod) % mod;
}
long long fast_pow(long long a,long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1) ret = a * ret % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0;i < n;i++) a[i] = s[i] - '0';
    long long ans = 0;
    fac[0] = 1;
    for (int i = 1;i < N;i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[N - 1] = fast_pow(fac[N - 1],mod - 2) % mod;
    for (int i = N - 2;i >= 0;i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    for (int j = 0;j < 9;j++)
    {
        vector<int> b;
        for (int v : a)
        {
            if (v == j || v == j + 1)
            {
                b.push_back(v);
            }
        }
        int c2 = 0,c1 = 0;
        for (int x : b)
        {
            if (x == j + 1) c2++;
        }
        for (int x : b)
        {
            if (x == j) c1++;
            else 
            {
                c2--;
            }
            if (x == j)
            {
                int total = c1 + c2 - 1;
                ans = (ans + comb(total,c1)) % mod;
            }
        }
    }
    cout << ans << endl;
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