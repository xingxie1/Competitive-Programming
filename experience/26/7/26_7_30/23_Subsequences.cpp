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

class segtree
{
    int n;
    vt mn;
    void up(int p) 
    {
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
    }
    void update(int p,int st,int ed,int id,int v)
    {
        if (st == id && ed == id) 
        {
            mn[p] = min(mn[p],v);
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,v);
        else update(p << 1 | 1, m + 1,ed,id,v);
        up(p);
    }
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return mn[p];
        }
        int m = st + ed >> 1;
        int res = INT_MAX / 2;
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(int _n) 
    {
        n = _n;
        mn.assign(n << 2,INT_MAX / 2);
    }
    void update(int id,int v)
    {
        update(1,0,n - 1,id,v);
    }
    int query(int l,int r) 
    {
        if (l > r || r < 0 || l > n) return INT_MAX / 2;
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n),tmp;
    for (int i = 0;i < n;i++) cin >> a[i];
    tmp = a;
    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int m = tmp.size();
    vt pos(n);
    vt L(n),R(n);
    for (int i = 0;i < n;i++) 
    {
        pos[i] = ranges::lower_bound(tmp,a[i]) - tmp.begin();
        L[i] = ranges::lower_bound(tmp,2 * a[i]) - tmp.begin();
        R[i] = ranges::upper_bound(tmp,3 * a[i]) - tmp.begin() - 1;
    }
    vvpii qs(n);
    for (int i = 0;i < q;i++) 
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        qs[l].push_back({r,i});
    }
    vt pre(n),ans(q,1);
    for (int i = 0;i < n;i++) pre[i] = i;
    for (int len = 2;len <= 60;len++)
    {
        segtree tr(m);
        vt cur(n,INT_MAX / 2);
        int f = 0;
        for (int i = n - 1;i >= 0;i--)
        {
            int x = tr.query(L[i],R[i]);
            cur[i] = x;
            if (x != INT_MAX / 2) f = 1;
            if (pre[i] != INT_MAX / 2) 
            {
                tr.update(pos[i],pre[i]);
            }
        }
        if (!f) break;
        int mn = INT_MAX / 2;
        for (int i = n - 1;i >= 0;i--) 
        {
            mn = min(mn,cur[i]);
            for (auto& [r,id] : qs[i])
            {
                if (mn <= r) ans[id] = len;
            }
        }
        pre = cur;
    }
    for (int x : ans) cout << x << endl;
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