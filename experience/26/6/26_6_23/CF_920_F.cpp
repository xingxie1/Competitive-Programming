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
const int N = 1000005; // 最大筛到 N
vector<int> D(N + 1);
auto init = [] 
{
    for (int i = 1;i <= N;i++) 
    {
        for (int j = i;j <= N;j += i) D[j]++;
    }
    return 0;
}();

class segtree
{
    vll sum;
    vt mx;
    int n;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void build(int p,int l,int r,vt& a)
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
    int query_max(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return mx[p];
        int m = st + ed >> 1;
        int res = 0;
        if (l <= m) res = max(res,query_max(p << 1,st,m,l,r));
        if (r > m) res = max(res,query_max(p << 1 | 1,m + 1,ed,l,r));
        return res;
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
        if (mx[p] <= 2) return ;
        if (st == ed) 
        {
            mx[p] = sum[p] = D[sum[p]];
            return ;
        }
        int m = st + ed >> 1;
        if (l <= m) update(p << 1,st,m,l,r);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r);
        up(p);
    }
public:
    segtree(vt& a) 
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
    int n,q;
    cin >> n >> q;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (q--) 
    {
        int op;
        cin >> op;
        int l,r;
        cin >> l >> r;
        l--;r--;
        if (op == 1) tr.update(l,r);
        else cout << tr.query(l,r) << endl;
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