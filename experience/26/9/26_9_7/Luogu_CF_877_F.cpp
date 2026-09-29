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

struct Query
{
    int l,r,id;
};  

void solve()
{
    int n,k;
    cin >> n >> k;
    vpii a(n + 1);
    int B = sqrt(n) + 1;
    for (int i = 1;i <= n;i++) cin >> a[i].fi;
    for (int i = 1;i <= n;i++) cin >> a[i].se;
    int q;
    cin >> q;
    vector<Query> qs(q);
    for (int i = 0;i < q;i++) 
    {
        cin >> qs[i].l >> qs[i].r;
        qs[i].l--;
        qs[i].id = i;
    }
    sort(qs.begin(),qs.end(),[&](auto& x,auto& y){
        int bx = x.l / B;
        int by = y.l / B;
        if (bx != by) return bx < by;
        if (bx & 1) return x.r > y.r;
        return x.r < y.r;
    });
    int L = 0,R = -1;
    ll res = 0;
    vll pre(n + 1);
    for (int i = 1;i <= n;i++) 
    {
        ll x = a[i].se;
        if (a[i].fi == 2) x = -x;
        pre[i] = pre[i - 1] + x;
    }
    vll val = pre;
    ranges::sort(val);
    val.erase(unique(val.begin(),val.end()),val.end());
    vt id(n + 1),left(n + 1,-1),right(n + 1,-1);
    for (int i = 0;i <= n;i++)
    {
        id[i] = ranges::lower_bound(val,pre[i]) - val.begin();
        auto it = ranges::lower_bound(val,pre[i] - k);
        if (it != val.end() && *it == pre[i] - k) left[i] = it - val.begin();
        it = ranges::lower_bound(val,pre[i] + k);
        if (it != val.end() && *it == pre[i] + k) right[i] = it - val.begin();
    }
    vll cnt(val.size());
    auto addl = [&](int i)
    {
        if (right[i] != -1) res += cnt[right[i]];
        cnt[id[i]]++;
    };
    auto addr = [&](int i)
    {
        if (left[i] != -1) res += cnt[left[i]];
        cnt[id[i]]++;
    };
    auto dell = [&](int i)
    {
        cnt[id[i]]--;
        if (right[i] != -1) res -= cnt[right[i]];
    };
    auto delr = [&](int i) 
    {
        cnt[id[i]]--;
        if (left[i] != -1) res -= cnt[left[i]];
    };
    vll ans(q);
    for (auto& [l,r,id] : qs)
    {
        while (R < r) addr(++R);
        while (R > r) delr(R--);
        while (L < l) dell(L++);
        while (L > l) addl(--L);
        ans[id] = res;
    }
    for (ll x : ans) cout << x << endl;
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