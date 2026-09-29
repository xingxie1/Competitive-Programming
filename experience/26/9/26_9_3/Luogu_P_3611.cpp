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
    vt mn,add,mx;
    void up(int p)
    {
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void build(int p,int l,int r,vt& a)
    {
        if (l == r) 
        {
            mn[p] = a[l];
            mx[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void apply(int p,int v)
    {
        mn[p] += v;
        mx[p] += v;
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
            mn[p] += v;
            mx[p] += v;
            add[p] += v;
            return ;
        }
        int m = st + ed >> 1;
        down(p);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    int query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed) return mn[p];
        int m = st + ed >> 1;
        down(p);
        int res = INT_MAX / 2;
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
    int query_max(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed) return mx[p];
        int m = st + ed >> 1;
        down(p);
        int res = 0;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree (vt& a) 
    {
        n = a.size();
        mn.assign(n << 2,INT_MAX / 2);
        mx.assign(n << 2,0);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,int v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
    int query_max(int l,int r) 
    {
        return query_max(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,t;
    cin >> n >> t;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    auto check = [&](int k) 
    {
        vt tmp(a.begin(),a.begin() + k);
        segtree tr(tmp);
        int i = k;
        int ans = 0;
        while (i < n) 
        {
            int mn = tr.query(0,k - 1);
            tr.update(0,k - 1,-mn);
            ans += mn;
            // for (int i = 0;i < k;i++) cout << tr.query(i,i) << " ";
            // cout << endl;
            // cout << mn << " " << ans << endl;
            if (ans > t) return false;
            while (tr.query(0,k - 1) == 0 && i < n)
            {
                int ll = -1,rr = k;
                while (ll + 1 < rr)
                {
                    int m = (ll + rr) / 2;
                    // cout << m << " " << tr.query(0,m) << endl;
                    if (tr.query(0,m) == 0) rr = m;
                    else ll = m;
                }
                // cout << "r : " << rr << endl;
                // cout << 
                tr.update(rr,rr,a[i++]);
            }
        }
        // for (int i = 0;i < k;i++) cout << tr.query(i,i) << " ";
        // cout << endl;
        ans += tr.query_max(0,k - 1);
        // cout << ans << endl;
        return ans <= t;
    };
    int l = 0,r = n + 1;
    while (l + 1 < r)
    {
        int m = l + r >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << endl;
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