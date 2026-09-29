#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vll a(n + 1);
    int B = sqrt(n);
    for (int i = 1;i <= n;i++) cin >> a[i];
    int cnt = (n + B - 1) / B;
    vll sum(cnt),add(cnt);
    auto bel = [&](int x) 
    {
        return (x - 1) / B;
    };
    for (int i = 1;i <= n;i++)
    {
        sum[bel(i)] += a[i];
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l,r;
            ll x;
            cin >> l >> r >> x;
            int bl = bel(l);
            int br = bel(r);
            for (int i = bl + 1;i <= br - 1;i++) 
            {
                add[i] += x;
            }
            for (int i = max(br * B + 1,l);i <= r;i++) 
            {
                a[i] += x;
                sum[br] += x;
            }
            if (bl != br)
            {
                for (int i = l;i <= min((bl + 1) * B,r);i++) 
                {
                    a[i] += x;
                    sum[bl] += x;
                }
            }
        }
        else 
        {
            int l,r;
            cin >> l >> r;
            int bl = bel(l);
            int br = bel(r);
            ll res = 0;
            for (int i = bl + 1;i <= br - 1;i++) res += sum[i] + add[i] * B;
            for (int i = max(br * B + 1,l);i <= r;i++) 
            {
                res += a[i] + add[br];
            }
            if (bl != br)
            {
                for (int i = l;i <= min((bl + 1) * B,r);i++) 
                {
                    res += a[i] + add[bl];
                }
            }
            cout << res << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}