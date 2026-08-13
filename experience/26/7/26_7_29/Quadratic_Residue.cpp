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
    ll p;
    cin >> p;
    ll rrr = sqrt(p);
    if (rrr * rrr == p)
    {
        ll x1 = sqrt(p),x2 = p / 2;
        cout << x1 << " " << x2 << " " << 1LL * x2 * x2 << endl;
        return ;
    }
    if (p == 2) 
    {
        cout << "12 1 71" << endl;
        return ;
    }
    if (p == 3) 
    {
        cout << "4 1 13" << endl;
        return;
    }
    if (p == 5)
    {
        cout << "1 2 4" << endl;
        return ;
    }
    if (p == 6) 
    {
        cout << "6 3 15" << endl;
        return ;
    }
    if (p == 7) 
    {
        cout << "1 3 2" << endl;
        return ;
    }
    if (p % 2 == 1) 
    {
        ll x1 = p / 2,x2 = p / 2,k = (x1 - 3) / 2;
        ll r = x2 * x2 % p;
        ll q = r + k * p;
        cout << x1 << " " << x2 << " " << q << endl;
    }
    else 
    {
        ll x1 = p / 2,x2 = p / 2,q = 0;
        if ((p / 2) % 2) q = 1LL * x1 * (x1 - 2);
        else q = p;
        cout << x1 << " " << x2 << " " << q << endl;
    }
    // ll x2 = p / 2;
    // ll r = (1LL * x2 * x2) % p;
    // vvll ans;
    // for (int k = 0;k <= 1000;k++)
    // {
    //     int q = r + p * k;
    //     if (q == 0) continue;
    //     for (int x = 1;x < q;x++)
    //     {
    //         ll s = 1LL * x * x - p;
    //         if (s % q == 0) 
    //         {
    //             ans.push_back({x,x2,p,r + p * k});
    //             // cout << x << " " << x2 << " " << r + p * k << endl;
    //         }
    //     }
    // }
    // ranges::sort(ans);
    // for (auto& e : ans) 
    // {
    //     for (ll x : e) cout << x << " ";
    //     cout << endl;
    // }
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