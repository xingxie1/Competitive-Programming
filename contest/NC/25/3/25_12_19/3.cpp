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

ll qpow(ll a,ll b,ll m)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}
void solve()
{
    ll a,b,m;
    cin >> a >> b >> m;
    ll ans = 0;
    map<int,int> cnt;
    for (int i = 0;i < m;i++)
    {
        cnt[qpow(i,a,m)] ++;
    }
    // for (auto it = cnt.begin();it != cnt.end();it++)
    // {
    //     cout << it->fi << " " << it -> se << endl;
    // }
    for (int i = 0;i < m;i++)
    {
        int x = qpow(i,b,m);
        ans += cnt[x];

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