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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vpii b;
    int ans = 0;
    int f = 0;
    for (int i = 0;i < n;i++)
    {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        ans += j - i - 1;
        b.push_back({a[i],j - i});
        i = j - 1;
    }
    ans = n - ans;
    int mx = 0;
    for (int i = 1;i < b.size();i++)
    {
        if (b[i].se == 1 && b[i - 1].se == 1) continue;
        if (b[i].se >= 2 && b[i - 1].se >= 2) 
        {
            mx = 2;
            break;
        }
        if (b[i].se == 1)
        {
            if (i + 1 >= b.size() || b[i - 1].fi != b[i + 1].fi) mx = max(mx,1);
        }
        if (b[i - 1].se == 1) 
        {
            if (i - 2 < 0 || b[i - 2].fi != b[i].fi) mx = max(mx,1);
        }
        // if ((b[i].se > 1 || b[i - 1].se > 1) && (i - 2 < 0 || b[i].fi != b[i - 2].fi) && (i + 1 >= b.size() || b[i - 1].fi != b[i + 1].fi)) 
        // {
        //     mx = max(mx,1);
        // }
        // if (b[i].se > 1 && i + 1 < b.size())
        // {
        //     mx = max(mx,1);
        // }
    }
    cout << ans + mx << endl;
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