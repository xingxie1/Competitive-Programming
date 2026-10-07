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
    int s1 = 0,s2 = 0;
    map<int,int> cnt1,cnt2;
    s1 = a[0] + a[2];
    s2 = a[1] + a[3];
    for (int i = 5;i < n;i += 2)
    {
        s2 -= a[i];
        cnt2[s2]++;
        s2 += 2 * a[i];
        s2 -= a[i - 4];
    }
    ll ans = 0;
    for (int i = 4;i < n;i += 2)
    {
        s1 -= a[i];
        ans += cnt1[s1] + cnt2[s1];
        cnt1[s1]++;
        if (i >= 6 && a[i - 4] + a[i - 2] - a[i] == a[i - 6] + a[i - 4] - a[i - 2]) ans--;
        if (i >= 8 && a[i - 8] + a[i - 6] - a[i - 4] == a[i - 4] + a[i - 2] - a[i]) ans--;
        s1 -= a[i - 4];
        s1 += 2 * a[i];
    }
    s2 = a[1] + a[3];
    cnt2.clear();
    for (int i = 5;i < n;i += 2)
    {
        s2 -= a[i];
        ans += cnt2[s2];
        cnt2[s2]++;
        if (i >= 6 && a[i - 4] + a[i - 2] - a[i] == a[i - 6] + a[i - 4] - a[i - 2]) ans--;
        if (i >= 8 && a[i - 8] + a[i - 6] - a[i - 4] == a[i - 4] + a[i - 2] - a[i]) ans--;
        s2 -= a[i - 4];
        s2 += 2 * a[i];
    }
    cout << ans << endl;
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