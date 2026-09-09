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
    ll s;
    cin >> s;
    int n = 7;
    vll f(n + 1);
    for (int i = 1;i <= 7;i++) cin >> f[i];
    ll l = -1,r = s + 1;
    auto check = [&](ll x)
    {
        ll a = f[1],b = f[2],c = f[4];
        ll fab = f[3],fac = f[5],fbc = f[6];
        vll nf = f;
        ll d1 = b - c;
        ll d2 = fab - fac;
        ll t = d1 + d2;
        if (a >= x)
        {
            b += fab;
            c += fac;
            if (c < x) 
            {
                if (c + fbc <= x) 
                {
                    c += fbc;
                    fbc = 0;
                }
                else 
                {
                    fbc -= x - c;
                    c += x - c;
                }
            }
            b += fbc;
            ll fabc = f[7];
            fabc -= max(0LL,x - a) + max(0LL,x - b) + max(0LL,x - c);
            return fabc >= 0;
        }
        if (t > 0)
        {
            if (t <= fab) 
            {
                if (a + t <= x) 
                {
                    a += t;
                    fab -= t;
                }
                else 
                {
                    fab -= x - a;
                    a += x - a;
                }
            }
            else 
            {
                if (a + fab <= x)
                {
                    a += fab;
                    fab = 0;
                }
                else 
                {
                    fab -= x - a;
                    a += x - a;
                }
            }
        }
        else if (t < 0) 
        {
            t = -t;
            if (t <= fac) 
            {
                if (a + t <= x) 
                {
                    a += t;
                    fac -= t;
                }
                else 
                {
                    fac -= x - a;
                    a += x - a;
                }
            }
            else 
            {
                if (a + fac <= x)
                {
                    a += fac;
                    fac = 0;
                }
                else 
                {
                    fac -= x - a;
                    a += x - a;
                }
            }
        }
        ll r = (x - a);
        ll r1 = r / 2;
        ll r2 = r / 2;
        r -= r1 + r2;
        if (fab >= r1) 
        {
            a += r1;
            fab -= r1;
        }
        else 
        {
            a += fab;
            fab = 0;
        }
        if (fac >= r2) 
        {
            a += r2;
            fac -= r2;
        }
        else 
        {
            a += fac;
            fac = 0;
        }
        if (a < x)
        {
            if (fab) 
            {
                if (x - a <= fab)
                {
                    fab -= x - a;
                    a += x - a;
                }
                else 
                {
                    a += fab;
                    fab = 0;
                }
            }
            if (fac) 
            {
                if (x - a <= fac)
                {
                    fac -= x - a;
                    a += x - a;
                }
                else 
                {
                    a += fac;
                    fac = 0;
                }
            }
        }
        b += fab;
        c += fac;
        if (c < x) 
        {
            if (c + fbc <= x) 
            {
                c += fbc;
                fbc = 0;
            }
            else 
            {
                fbc -= x - c;
                c += x - c;
            }
        }
        b += fbc;
        ll fabc = f[7];
        fabc -= max(0LL,x - a) + max(0LL,x - b) + max(0LL,x - c);
        return fabc >= 0;
    };
    while (l + 1 < r)
    {
        ll m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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