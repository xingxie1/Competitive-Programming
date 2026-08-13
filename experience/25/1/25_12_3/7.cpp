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
    int d;
    cin >> d;
    int n = 50005;
    vt primes,isprime(n + 1,1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2;i <= n;i++)
    {
        if (isprime[i]) primes.push_back(i);
        for (int p : primes)
        {
            if (1LL * i * p > n) break;
            isprime[i * p] = 0;
            if (i % p == 0) break;
        }
    }
    // for (int i = 0;i < primes.size();i++)
    // {
    //     cout << primes[i] << " ";
    //     if (i % 10 == 0) cout << endl;
    // }
    auto it1 = lower_bound(primes.begin(),primes.end(),1 + d);
    int d1 = *it1;
    auto it2 = lower_bound(primes.begin(),primes.end(),d1 + d);
    int d2 = *it2;

    cout << 1LL * d1 * d2 << endl;
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