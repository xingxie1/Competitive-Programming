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
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vpii a(m);
    for (int i = 0;i < m;i++) 
    {
        int l;
        cin >> l;
        l--;
        a[i].fi = l;
    }
    for (int i = 0;i < m;i++) 
    {
        int r;
        cin >> r;
        r--;
        a[i].se = r;
    }
    int q;
    cin >> q;
    vt d(n + 1);
    while (q--)
    {
        int x;
        cin >> x;
        x--;
        auto it = ranges::lower_bound(a,pair{x + 1,-1});
        it--;
        int l = it->fi,r = it->se;
        int a = min(x,l + r - x),b = max(x,l + r - x);
        d[a]++;
        d[b + 1]--;
    }
    int sum = 0;
    int last = -1;
    for (auto& [l,r] : a)
    {
        for (int i = l;i <= (l + r) / 2;i++)
        {
            sum += d[i];
            if (sum % 2 == 1) swap(s[i],s[l + r - i]);
        }
        for (int i = (l + r) / 2 + 1;i <= r;i++)
        {
            sum += d[i];
        }
    }
    cout << s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}