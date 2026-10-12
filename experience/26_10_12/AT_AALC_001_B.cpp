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
    vll tr,add;
    void up(int p) 
    {
        tr[p] = min(tr[p << 1],tr[p << 1 | 1]);
    }
    void build(int p,int st,int ed,vt& a)
    {
        if (st == ed) 
        {
            tr[p] = a[st];
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p);
    }
    void apply(int p,ll v) 
    {
        tr[p] += v;
        add[p] += v;
    }
    void down(int p)
    {
        if (add[p])
        {
            apply(p << 1,add[p]);
            apply(p << 1 | 1,add[p]);
            add[p] = 0;
        }
    }
    void update(int p,int st,int ed,int l,int r,int v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,v);
            return ;
        }
        int m = st + ed >> 1;
        down(p);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        int m = st + ed >> 1;
        ll res = LLONG_MAX / 2;
        down(p);
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree (vt& a) 
    {
        n = a.size();
        tr.assign(n << 2,LLONG_MAX / 2);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,int v)
    {
        update(1,0,n - 1,l,r,v);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l,r,x;
            cin >> l >> r >> x;
            l--;r--;
            tr.update(l,r,x);
        }
        else 
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            cout << tr.query(l,r) << endl;
        }
    }
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