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
    vll sum,mx;
    void up(int p)
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void build(int p,int st,int ed,vll& a)
    {
        if (st == ed)
        {
            sum[p] = mx[p] = a[st];
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r)
    {
        if (mx[p] == 1) return ;
        if (st == ed)
        {
            sum[p] = sqrt(sum[p]);
            mx[p] = sqrt(mx[p]);
            return ;
        }
        int m = st + ed >> 1;
        if (l <= m) update(p << 1,st,m,l,r);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed) return sum[p];
        int m = st + ed >> 1;
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
        mx.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r)
    {
        update(1,0,n - 1,l,r);
    }
    ll query(int l,int r)
    {
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n;
    int cnt = 1;
    while (cin >> n)
    {
        cout << "Case #" << cnt++ << ":" << endl;
        vll a(n);
        for (int i = 0;i < n;i++) cin >> a[i];
        segtree tr(a);
        int q;
        cin >> q;
        while (q--)
        {
            int op,x,y;
            cin >> op >> x >> y;
            x--;y--;
            if (op == 0) tr.update(x,y);
            else cout << tr.query(x,y) << endl;
        }
        cout << endl;
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