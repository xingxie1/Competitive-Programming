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

class segtree
{
    vll cnt,mn,add;
    int n;
    void up(int p) 
    {
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
        cnt[p] = cnt[p << 1] + cnt[p << 1 | 1];
    }
    void build(int p,int l,int r,vll& a) 
    {
        if (l == r) 
        {
            mn[p] = a[l];
            cnt[p] = 1;
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void apply(int p,ll v) 
    {
        if (cnt[p] == 0) return ;
        mn[p] += v;
        add[p] += v;
    }
    void down(int p,int ll,int lr)
    {
        if (add[p]) 
        {
            apply(p << 1,add[p]);
            apply(p << 1 | 1,add[p]);
            add[p] = 0;
        }
    }
    ll query(int p,int st,int ed,int l,int r,ll v) 
    {
        if (cnt[p] == 0) return 0;
        if (l <= st && r >=ed && mn[p] >= v)
        {
            apply(p,-v);
            return cnt[p] * v;
        }
        if (st == ed) 
        {
            ll res = mn[p];
            mn[p] = LLONG_MAX / 2;
            cnt[p] = 0;
            add[p] = 0;
            return res;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res += query(p << 1,st,m,l,r,v);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
        return res;
    }
public: 
    segtree (vll& a) 
    {
        n = a.size();
        mn.assign(n << 2,0);
        add.assign(n << 2,0);
        cnt.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    ll query(int l,int r,ll v)
    {
        return query(1,0,n - 1,l,r,v);
    }
};
void solve()
{
    int n,q;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    cin >> q;
    while (q--)
    {
        int l,r;
        ll v;
        cin >> l >> r >> v;
        l--;r--;
        cout << tr.query(l,r,v) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}