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
    int n;
    cin >> n;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    ll ans = 0;
    umap<ll,int> cnt,cnt2;
    cnt.reserve(n * n / 2);
    cnt2.reserve(n * n / 2);
    for (int i = 0;i < n;i++) 
    {
        for (int j = i + 1;j < n;j++)
        {
            ll x1 = a[i].fi,y1 = a[i].se;
            ll x2 = a[j].fi,y2 = a[j].se;
            ans -= cnt2[(x1 + x2) * 20000001 + y1 + y2];
            cnt2[(x1 + x2) * 20000001 + y1 + y2]++;
            ll dx = x2 - x1,dy = y2 - y1;
            if (dx == 0) 
            {
                dy = 1;
            }
            else if (dy == 0)
            {
                dx = 1;
            }
            else 
            {
                ll g = gcd(dx,dy);
                dx /= g;
                dy /= g;
                if (dx < 0) 
                {
                    dx *= -1;
                    dy *= -1;
                } 
            }
            ans += cnt[dx * 20000001 + dy];
            cnt[dx * 20000001 + dy]++;
        }
    }
    cout << ans << endl;
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