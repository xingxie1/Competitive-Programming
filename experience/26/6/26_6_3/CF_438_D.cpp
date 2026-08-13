#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    int n;
    vll tr,mx;
    void up(int p) 
    {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void build (int p,int l,int r,const vll& a) 
    {
        if (l == r) 
        {
            tr[p] = a[l];
            mx[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void set(int p,int st,int ed,int id,ll v) 
    {
        if (st == id && ed == id) 
        {
            tr[p] = v;
            mx[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) set(p << 1,st,m,id,v);
        else set(p << 1 | 1,m + 1,ed,id,v);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r,ll v) 
    {
        if (st == ed)
        {
            tr[p] %= v;
            mx[p] %= v;
        }
        else 
        {
            int m = st + ed >> 1;
            if (l <= m && mx[p << 1] >= v) update(p << 1,st,m,l,r,v);
            if (r > m && mx[p << 1 | 1] >= v) update(p << 1 | 1,m + 1,ed,l,r,v);
            up(p);
        }
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        ll res = 0;
        int m = st + ed >> 1;
        if (l <= m) res += query(p << 1,st,m,l,r);
        if (r > m)  res += query(p << 1 | 1,m + 1,ed,l,r);
        return res;
    } 
public:
    segtree(const vll& a )
    {
        n = a.size();
        tr.assign(n << 2,0);
        mx.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void set(int id,ll v) 
    {
        set(1,0,n - 1,id,v);
    }
    void update(int l,int r,ll v) 
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
    int n,m;
    cin >> n >> m;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (m-- ) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int l, r;
            cin >> l >> r;
            l--;r--;
            cout << tr.query(l,r) << endl;
        }
        else if (op == 2)
        {
            ll l,r,v;
            cin >> l >> r >> v;
            l--;r--;
            tr.update(l,r,v);
        }
        else 
        {
            ll id,v;
            cin >> id >> v;
            id--;
            tr.set(id,v);
        }
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