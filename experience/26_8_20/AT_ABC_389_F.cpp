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
    vll sum,add;  
    void up(int p)
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void apply(int p,int len,ll v)
    {
        sum[p] += len * v;
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
    ll query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return sum[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res += query(p << 1,st,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
        return res;
    } 
public: 
    segtree(vll& a)
    {
        n = a.size();
        sum.assign(n << 2,0);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
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
    int n;
    cin >> n;
    vll tmp(5e5 + 1);
    ranges::iota(tmp,0);
    segtree tr(tmp);
    for (int i = 0;i < n;i++) 
    {
        int L,R;
        cin >> L >> R;
        int l = 0,r = 5e5 + 1;
        while (l + 1 < r)
        {
            int m = l + r >> 1;
            if (tr.query(m,m) >= L) r = m;
            else l = m;
        }
        int l2 = 0,r2 = 5e5 + 1;
        while (l2 + 1 < r2)
        {
            int m2 = l2 + r2 >> 1;
            if (tr.query(m2,m2) > R) r2 = m2;
            else l2 = m2;
        }
        // cout << l << " " << r << " " << l2 << " " << r2 << endl;
        tr.update(r,l2,1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << tr.query(x,x) << endl;
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