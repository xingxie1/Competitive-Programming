#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt primes,isprime(n + 1,1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2;i <= n;i++)
    {
        if (isprime[i])primes.push_back(i);
        for (int p : primes)
        {
            if (1LL * i * p > n) break;
            isprime[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    int cnt = 0;
    for (int i = 2;i < primes.size();i++)
    {
        for (int j = 0;j + 1 < i;j++)
        {
            if (primes[j] + primes[j + 1] + 1 == primes[i]) cnt++;
        }
    }
    if (cnt >= k) cout << "YES" << endl;
    else cout << "NO" << endl;

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