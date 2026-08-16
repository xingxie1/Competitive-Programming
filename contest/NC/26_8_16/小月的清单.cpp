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
    vll sum,mn,add;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
    }
    void build(int p,int l,int r,vll& a) 
    {
        if (l == r) 
        {
            sum[p] = mn[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void down(int p,int ll,int lr) 
    {
        if (add[p]) 
        {
            sum[p << 1] += add[p] * ll;
            sum[p << 1 | 1] += add[p] * lr;
            add[p << 1] += add[p];
            add[p << 1 | 1] += add[p];
            mn[p << 1] += add[p];
            mn[p << 1 | 1] += add[p];
            add[p] = 0;
        }
    }
    void update(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            add[p] += v;
            sum[p] += (ed - st + 1) * v;
            mn[p] += v;
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
        if (l <= st && r >= ed) return mn[p];
        int m = st + ed >> 1;
        ll res = LLONG_MAX / 2;
        down(p,m - st + 1,ed - m);
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
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
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
    void update(int l,int r,ll v)
    {
        update(1,0,n - 1,l,r,v);
    } 
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    string s;
    cin >> s;
    vll sum(n);
    for (int i = 0;i < n;i++)
    {
        if (i == 0) 
        {
            if (s[i] == '+') sum[i] = a[i];
            else sum[i] = -a[i];
        }
        else 
        {
            if (s[i] == '+') sum[i] = sum[i - 1] + a[i];
            else sum[i] = sum[i - 1] - a[i];
        }
    }
    segtree tr(sum);
    while (q--)
    {
        int i;
        char c;
        cin >> i >> c;
        i--;
        if (s[i] == c) 
        {
            if (tr.query(0,n - 1) < 0) NO;
            else YES;
        }
        else 
        {
            if (s[i] == '+') 
            {
                tr.update(i,n - 1,-2 * a[i]);
                if (tr.query(0,n - 1) < 0) NO;
                else YES;
                tr.update(i,n - 1,2 * a[i]);
            }
            else 
            {
                tr.update(i,n - 1,2 * a[i]);
                if (tr.query(0,n - 1) < 0) NO;
                else YES;
                tr.update(i,n - 1,-2 * a[i]);
            }
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