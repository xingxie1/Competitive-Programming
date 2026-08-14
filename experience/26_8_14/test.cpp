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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

double rand_real(double a, double b)
{
    uniform_real_distribution<double> dist(a, b);
    return dist(rng);
}

void solve()
{
    ll x = rng(),a = rng(),b = rng();
    auto f1 = [&]()
    {
        ll l = 0, r = INT_MAX / 2;
        auto check = [&](ll m)
        {
            ll l1 = -1, r1 = m + 1;
            int cnt = 100;
            while (cnt--)
            {
                i128 m1 = (i128)(2 * l1 + r1) / 3, m2 = (i128)(l1 + 2 * r1) / 3;
                i128 k = m - m1 + 1;
                i128 sum1 = (i128)((m1 + 1) * a - (m1 - 1)) * m1 / 2;
                i128 sum2 = (i128)((m2 + 1) * a - (m2 - 1)) * m2 / 2;
                i128 res1 = 0, res2 = 0;
                if (m1 * a - m1 > m - m1)
                {
                    res1 = (i128)(m - m1) * (m1 * a - m1) - (i128)(m - m1) * (m - m1 - 1) / 2;
                }
                else
                {
                    res1 = (i128)(m1 * a - m1 + 1) * (m1 * a - m1) / 2;
                }
                if (m2 * a - m2 > m - m2)
                {
                    res2 = (i128)(m - m2) * (m2 * a - m2) - (i128)(m - m2) * (m - m2 - 1) / 2;
                }
                else
                {
                    res2 = (i128)(m2 * a - m2 + 1) * (m2 * a - m2) / 2;
                }
                sum1 += res1;
                sum1 += (i128)(m - m1) * b;
                sum2 += res2;
                sum2 += (i128)(m - m2) * b;
                if (sum1 > sum2)
                    r1 = m2;
                else
                    l1 = m1;
            }
            i128 mx = 0;
            for (int i = l1 - 3; i <= r1 + 3; i++)
            {
                if (i < 0)
                    continue;
                i128 sum = (i128)((i + 1) * a - (i - 1)) * i / 2;
                i128 res = 0;
                if (i * a - i > m - i)
                {
                    res = (i128)(m - i) * (i * a - i) - (i128)(m - i) * (m - i - 1) / 2;
                }
                else
                {
                    res = (i128)(i * a - i + 1) * (i * a - i) / 2;
                }
                sum += res;
                sum += (i128)(m - i) * b;
                mx = max(mx, sum);
            }
            if (mx >= x)
                return true;
            return false;
        };
        while (l + 1 < r)
        {
            ll m = l + r >> 1;
            if (check(m))
                r = m;
            else
                l = m;
        }
        return r;
    };
    auto f2 = [&]()
    {
        if (a == 1)
        {
            return 1LL * (x + b - 1) / b;
        }
        i128 sum = 0, sa = 0;
        ll ans = (x + b - 1) / b;
        for (ll i = 1;; i++)
        {
            sa += a;
            sum += sa;
            sa--;
            if (sum >= x)
            {
                ans = min(ans, i);
                break;
            }
            ll l = 0, r = INT_MAX / 2;
            while (l + 1 < r)
            {
                ll m = l + r >> 1;
                ll res = x - sum;
                if (sa < m)
                {
                    res -= (i128)(1 + sa) * sa / 2;
                }
                else
                {
                    res -= (i128)m * sa - (i128)(m * (m - 1)) / 2;
                }
                res -= (i128)m * b;
                if (res <= 0)
                    r = m;
                else
                    l = m;
            }
            ans = min(ans, i + r);
        }
        return ans;
    };
    ll ans1 = f1();
    ll ans2 = f2();
    if (ans1 != ans2)
    {
        cout << x << " " << a << " " << b << endl;
        cout << ans1 << " " << ans2 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}