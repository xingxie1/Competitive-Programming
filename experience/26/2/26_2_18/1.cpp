#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    map<int,ll> cnt;
    vpii g;
    for (int i = 0;i < n;i++)
    {
        g.emplace_back(a[i],i);
        int j = 0;
        for (auto& p : g)
        {
            p.fi = gcd(p.fi,a[i]);
            if (p.fi == g[j].fi) g[j].se = p.se;
            else g[++j] = p;
        }
        g.resize(j + 1);
        for (int k = 0;k < g.size();k++)
        {
            auto p = g[k];
            int x = p.fi,r = p.se;
            int l = 0;
            if (k - 1 >= 0)
            {
                l = g[k - 1].se + 1;
            }
            int d = r - l + 1;
            cnt[x] += d;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << cnt[x] << endl;
    }
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