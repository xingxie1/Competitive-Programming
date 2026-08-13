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

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class segtree
{
private:
    vector<ll> tree;
    vector<ll> lazy;
    vector<ll> mx;
    int n;
    void push_up(int p)
    {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    }
    void push_down(int p,int lenl,int lenr)
    {
        if (lazy[p] != 0)
        {
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            mx[p << 1] += lazy[p];
            mx[p << 1 | 1] += lazy[p];
            tree[p << 1] += lazy[p] * lenl;
            tree[p << 1 | 1] += lazy[p] * lenr;
            lazy[p] = 0;
        }
    }
    void build(int p,int l,int r,const vector<ll>& a)
    {
        if (l == r) 
        {
            tree[p] = a[l];
            mx[p] = a[l];
            return ;
        }
        int m = l + (r - l) / 2;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        push_up(p);
    }
    //区间[l,r]加上v
    void update(int p,int start,int end,int l,int r,ll v)
    {
        if (l <= start && end <= r) 
        {
            tree[p] += v * (end - start + 1);
            lazy[p] += v;
            mx[p] += v;
            return ;
        }
        int m = start + (end - start) / 2;
        push_down(p,m - start + 1,end - m);
        if (l <= m) update(p << 1,start,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,end,l,r,v);
        push_up(p);
    }
    void set(int p,int st,int ed,int id,int v) 
    {
        if (id == st && id == ed) 
        {
            tree[p] = v;
            mx[p] = v;
            lazy[p] = 0;
            return ;
        }
        int m = st + ed >> 1;
        push_down(p,m - st + 1,ed - m);
        if (id <= m) set(p << 1,st,m,id,v);
        else set(p << 1 | 1,m + 1,ed,id,v);
        push_up(p);
    }
    ll query(int p,int start,int end,int l,int r)
    {
        if (l <= start && end <= r) return tree[p];
        int m = start + (end - start) / 2;
        push_down(p,m - start + 1,end - m);

        ll res = 0;
        if (l <= m) res += query(p << 1,start,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,end,l,r);

        return res;
    }
    ll query_max(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return mx[p];
        int m = st + (ed - st) / 2;
        push_down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res = max(res,query_max(p << 1,st,m,l,r));
        if (r > m) res = max(res,query_max(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(const vector<ll>& a) 
    {
        n = a.size();
        tree.assign(4 * n,0);
        lazy.assign(4 * n,0);
        mx.assign(4 * n,0);
        if (n > 0) 
        {
            build(1,0,n - 1,a);
        }
    }
    //区间[l,r]加v
    void update(int l,int r,ll v)
    {
        if (l <= r && l >= 0 && r < n) 
        {
            update(1,0,n - 1,l,r,v);
        }
    }
    void set(int id,int v) 
    {
        set(1,0,n - 1,id,v);
    }
    //查询区间[l,r] 的和(下标0开始)
    ll query(int l,int r)
    {
        if (l <= r && l >= 0 && r < n) 
        {
            return query(1,0,n - 1,l,r);
        }
        return 0;
    }
    ll query_max(int l,int r)
    {
        if (l <= r && l >= 0 && r < n) 
        {
            return query_max(1,0,n - 1,l,r);
        }
        return 0;
    }
};



void solve()
{
    int n;
    cin >> n;
    vt a(n),last(n + 1,-1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    vll tmp(n);
    segtree tr1(tmp),tr2(tmp),tr3(tmp);
    for (int i = 0;i < n;i++)
    {
        int p = last[a[i]];
        int st2 = tr1.query_max(0,i - 1);
        int st3 = tr2.query_max(1,i - 1);
        if (i == 0) tr1.set(0,1);
        tr2.set(i,st2 + 1);
        tr3.set(i,st3 + 1);
        tr1.update(p + 1,i - 1,1);
        tr2.update(p + 1,i - 1,1);
        tr3.update(p + 1,i - 1,1);
        last[a[i]] = i;
    }
    cout << tr3.query_max(0,n - 1) << endl;
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