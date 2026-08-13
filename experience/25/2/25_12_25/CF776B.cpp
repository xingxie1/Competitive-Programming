#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vector<int> primes;
    vector<int> isprime(n + 2,1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2;i < n + 2;i++)
    {
        if (isprime[i]) primes.push_back(i);
        for (int p : primes)
        {
            if (p * i >= n + 2) break;
            isprime[p * i] = 0;
            if (i % p == 0) break;
        }
    }
    vector<int> ans(n + 2,1);
    for (int i = 2;i < n + 2;i++)
    {
        if (isprime[i])
        {
            for (int j = 2;j * i < n + 2;j++)
            {
                ans[j * i] = max(ans[j * i],ans[i] + 1);
            }
        }
    }
    int mx = 0;
    for (int x : ans) mx = max(x,mx);
    cout << mx << endl;
    for (int i = 2;i < n + 2;i++) cout << ans[i] << " ";
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