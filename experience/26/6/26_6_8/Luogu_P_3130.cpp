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
    vll sum,add,mn;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
    }
    void apply(int p,int len,ll v) 
    {
        sum[p] += v * len;
        mn[p] += v;
        add[p] += v;
    }
    void down(int p,int ll,int lr) 
    {
        if (add[p]) 
        {
            apply(p << 1,ll,add[p]);
            apply(p << 1 | 1,lr,add[p]);
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,vll& a) 
    {
        if (l == r) 
        {
            sum[p] = a[l];
            mn[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,ed - st + 1,v);
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    ll query_sum(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return sum[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res += query_sum(p << 1,st,m,l,r);
        if (r > m) res += query_sum(p << 1 | 1,m + 1,ed,l,r);
        return res; 
    }
    ll query_min(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return mn[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = LLONG_MAX;
        if (l <= m) res = min(res,query_min(p << 1,st,m,l,r));
        if (r > m) res = min(res,query_min(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(vll& a) 
    {
        n = a.size();
        sum.assign(n << 2,0);
        add.assign(n << 2,0);
        mn.assign(n << 2,LLONG_MAX / 2);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,ll v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    ll query_sum(int l,int r) 
    {
        return query_sum(1,0,n - 1,l,r);
    }
    ll query_min(int l,int r) 
    {
        return query_min(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (q--) 
    {
        char op;
        cin >> op;
        int l,r;
        cin >> l >> r;
        l--;r--;
        if (op == 'M') 
        {
            cout << tr.query_min(l,r) << endl;
        }
        else if (op == 'P') 
        {
            ll v;
            cin >> v;
            tr.update(l,r,v);
        }
        else cout << tr.query_sum(l,r) << endl;
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