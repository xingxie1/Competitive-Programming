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
    set<int> st = {4,7};
    for (int len = 2;len <= 9;len++)
    {
        set<int> nst = st;
        for (int x : st) 
        {
            string y1 = to_string(x) + '4';
            string y2 = to_string(x) + '7';
            nst.insert(stoi(y1));
            nst.insert(stoi(y2));
        }
        st = nst;
    }
    vll a;
    for (int x : st) a.push_back(x);
    int n = a.size();
    a.push_back(INT_MAX / 2);
    ll pl,pr,vl,vr,k;
    cin >> pl >> pr >> vl >> vr >> k;
    double ans = 0;
    ll x = vl;
    ll all = (vr - vl + 1) * (pr - pl + 1);
    while (1) 
    {
        int i = ranges::lower_bound(a,x) - a.begin();
        if (i <= n - k) 
        {
            int l = max(a[i + k - 1],pl);
            int r = min(a[i + k] - 1,pr);
            int len1 = min(a[i],vr) - x + 1;
            int len2 = r - l + 1;
            if (len2 > 0 && len1 > 0) ans += 1.0 * len1 * len2 / all;
        }
        else break;
        x = a[i] + 1;
    }
    x = pl;
    while (1)
    {
        int i = ranges::lower_bound(a,x) - a.begin();
        if (i <= n - k) 
        {
            int l = max(a[i + k - 1],vl);
            int r = min(a[i + k] - 1,vr);
            int len1 = min(a[i],pr) - x + 1;
            int len2 = r - l + 1;
            if (len2 > 0 && len1 > 0) ans += 1.0 * len1 * len2 / all;
        }
        else break;
        x = a[i] + 1;
    }
    if (k == 1)
    {
        for (int i = 0;i < n;i++)
        {
            if (a[i] >= pl && a[i] <= pr && a[i] >= vl && a[i] <= vr) ans -= 1.0 / all;
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