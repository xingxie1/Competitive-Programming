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

class segtree{
    int n;
    vll sum,mx;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    ll query_sum(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return sum[p];
        int m = st + ed >> 1;
        ll res = 0;
        if (l <= m) res += query_sum(p << 1,st,m,l,r);
        if (r > m) res += query_sum(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
    void update(int p,int st,int ed,int l,int r) 
    {
        if (st == ed) 
        {
            ll root = 1LL * sqrt(sum[p]);
            sum[p] = root;
            mx[p] = root;
        }
        else
        {
            int m = st + ed >> 1;
            if (l <= m && mx[p << 1] > 1) update(p << 1,st,m,l,r);
            if (r > m && mx[p << 1 | 1] > 1) update(p << 1 | 1,m + 1,ed,l,r);
            up(p);
        }
    }
    void build(int p,int l,int r,const vll& a) 
    {
        if (l == r) 
        {
            sum[p] = a[l];
            mx[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
public: 
    segtree(const vll& a) 
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
        return query_sum(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,m;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    cin >> m;
    while (m--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            if (l > r) swap(l,r);
            cout << tr.query(l,r) << endl;
        }
        else 
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            if (l > r) swap(l,r);
            tr.update(l,r);
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