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
    vvt cnt,upd;
    vt pow2;
    void up(int p)
    {
        for (int i = 0;i < 20;i++)
        {
            cnt[p][i] = cnt[p << 1][i] + cnt[p << 1 | 1][i];
        }
    }
    void build(int p,int l,int r,vt& a)
    {
        if (l == r)
        {
            for (int i = 0;i < 20;i++)
            {
                if (a[l] >> i & 1) cnt[p][i]++;
            }
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void apply(int p,int len,int i)
    {
        upd[p][i] ^= 1;
        cnt[p][i] = len - cnt[p][i];
    }
    void down(int p,int ll,int lr)
    {
        for (int i = 0;i < 20;i++)
        {
            if (upd[p][i])
            {
                apply(p << 1,ll,i);
                apply(p << 1 | 1,lr,i);
                upd[p][i] = 0;
            }
        }
    }
    void update(int p,int st,int ed,int l,int r,int x)
    {
        if (l <= st && r >= ed)
        {
            for (int i = 0;i < 20;i++)
            {
                if (x >> i & 1) apply(p,ed - st + 1,i);
            }
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,x);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,x);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            ll res = 0;
            for (int i = 0;i < 20;i++)
            {
                res += 1LL * cnt[p][i] * pow2[i];
            }
            return res;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res += query(p << 1,st,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
public:
    segtree (vt& a)
    {
        n = a.size();
        cnt.resize(n << 2);
        upd.resize(n << 2);
        for (int i = 0;i < n << 2;i++) 
        {
            cnt[i].assign(20,0);
            upd[i].assign(20,0);
        }
        pow2.resize(20);
        pow2[0] = 1;
        for (int i = 1;i < 20;i++) pow2[i] = pow2[i - 1] * 2;
        build(1,0,n - 1,a);
    }
    void update(int l,int r,int x)
    {
        update(1,0,n - 1,l,r,x);
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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    int q;
    cin >> q;
    while (q--)
    {
        int op,l,r;
        cin >> op >> l >> r;
        l--;r--;
        if (op == 1)
        {
            cout << tr.query(l,r) << endl;
        }
        else 
        {
            int x;
            cin >> x;
            tr.update(l,r,x);
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