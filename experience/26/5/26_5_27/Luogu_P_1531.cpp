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

class segtree{
    vll tr;
    int n;
    void push_up(int p) {tr[p] = max(tr[p << 1],tr[p << 1 | 1]);}
    void build(int p,int l,int r,const vll& a) 
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        if (l <= m) build(p << 1,l,m,a);
        if (r > m) build(p << 1 | 1,m + 1,r,a);
        push_up(p);
    }
    void update(int p,int l,int r,int id,ll v) 
    {
        if (l == r) 
        {
            tr[p] = max(tr[p],v);
            return ;
        }
        int m = l + r >> 1;
        if (id <= m) update(p << 1,l,m,id,v);
        else update(p << 1 | 1,m + 1,r,id,v);
        push_up(p); 
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        ll res = 0;
        int m = st + ed >> 1;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public :
    segtree(const vll& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        if (n > 0) build(1,0,n - 1,a);
    }
    void update(int idx,ll v)
    {
        update(1,0,n - 1,idx,v);
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
    while (m--) 
    {
        char op;
        cin >> op;
        int a,b;
        cin >> a >> b;
        if (op == 'Q') 
        {
            cout << tr.query(a - 1,b - 1) << endl;
        }
        else 
        {
            tr.update(a - 1,b);
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