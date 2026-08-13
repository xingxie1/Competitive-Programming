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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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

int MOD;
class segtree
{
    int n;
    vll tr;
    void push_up(int p)
    {
        tr[p] = max(tr[p << 1],tr[p << 1 | 1]);
    }
    void build(int p,int l,int r,const vll& a) 
    {
        if (l == r)
        {
            tr[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build (p << 1,l,m,a);
        build (p << 1 | 1,m + 1,r,a);
        push_up(p);
    }
    void update(int p,int st,int ed,int id,ll v) 
    {
        if (st == ed && st == id) 
        {
            tr[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,v);
        if (id > m) update(p << 1 | 1,m + 1,ed,id,v);
        push_up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        int m = st + ed >> 1;
        ll res = LLONG_MIN;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(const vll& a) 
    {
        n = a.size();
        tr.assign(n << 2,LLONG_MIN);
        build(1,0,n - 1,a);
    }
    void update(int id,ll v) 
    {
        update(1,0,n - 1,id,v);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n;
    cin >> n >> MOD;
    ll t = 0;
    int i = 0;
    vll a(n,LLONG_MIN);
    segtree tr(a);
    while (n--)
    {
        char op;
        cin >> op;
        if (op == 'A') 
        {
            ll x;
            cin >> x;
            x += t;
            x %= MOD;
            tr.update(i,x % MOD);
            i++;
        }
        else 
        {
            int l;
            cin >> l;
            ll ans = tr.query(i - l,i - 1);
            t = ans % MOD;
            cout << ans << endl;
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