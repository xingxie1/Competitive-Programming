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
    vll mn,add;
    void up(int p)
    {
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
    }
    void build(int p,int l,int r,vll& a)
    {
        if (l == r) 
        {
            mn[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void apply(int p,ll v)
    {
        mn[p] += v;
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
    void update(int p,int st,int ed,int l,int r,ll v)
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
        if (l <= st && r >= ed)
        {
            return mn[p];
        }
        down(p);
        int m = st + ed >> 1;
        ll res = LLONG_MAX / 2;
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(vll& a)
    {
        n = a.size();
        mn.assign(n << 2,LLONG_MAX / 2);
        add.assign(n << 2,0);
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
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int q;
    cin >> q;
    // a.insert(a.end(),a.begin(),a.end());
    segtree tr(a);
    cin.ignore();
    while (q--)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        vll qs;
        ll x;
        while (ss >> x) qs.push_back(x);
        int l = qs[0],r = qs[1];
        if (r < l) 
        {
            if (qs.size() == 3)
            {
                ll v = qs[2];
                tr.update(l,n - 1,v);
                tr.update(0,r,v);
            }
            else 
            {
                ll ans = min(tr.query(l,n - 1),tr.query(0,r));
                cout << ans << endl;
            }
        }
        else 
        {
            if (qs.size() == 3) 
            {
                ll v = qs[2];
                tr.update(l,r,v);
            }
            else 
            {
                ll ans = tr.query(l,r);
                cout << ans << endl;
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