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

class segtree 
{
    int n;
    vt sum,mx,add;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void build(int p,int l,int r,vt& a) 
    {
        if (l == r) 
        {
            sum[p] = mx[p] = a[l];
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
            mx[p << 1] += add[p];
            mx[p << 1 | 1] += add[p];
            add[p] = 0;
        }
    }
    void update(int p,int st,int ed,int l,int r,int v) 
    {
        if (l <= st && r >= ed) 
        {
            add[p] += v;
            sum[p] += (ed - st + 1) * v;
            mx[p] += v;
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return mx[p];
        int m = st + ed >> 1;
        int res = 0;
        down(p,m - st + 1,ed - m);
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(vt& a) 
    {
        n = a.size();
        sum.assign(n << 2,0);
        add.assign(n << 2,0);
        mx.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
    void update(int l,int r,int v)
    {
        update(1,0,n - 1,l,r,v);
    } 
};
void solve()
{
    int q;
    cin >> q;
    mset<int> L,R;
    while (q--)
    {
        char op;
        int l,r;
        cin >> op >> l >> r;
        if (op == '+') 
        {
            L.insert(l);
            R.insert(r);
        }
        else 
        {
            L.erase(L.find(l));
            R.erase(R.find(r));
        }
        if (L.empty()) NO;
        else if (*(--L.end()) <= *(R.begin())) NO;
        else YES;
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
