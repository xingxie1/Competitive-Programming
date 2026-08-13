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

class segtree
{
    int n;
    vt mn,mx,ans;
    void up(int p,int len) 
    {
        ans[p] = max(ans[p << 1],ans[p << 1 | 1]);
        if (mx[p << 1] > mn[p << 1 | 1]) ans[p] = max(ans[p],len / 2);
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void update(int p,int st,int ed,int i,int x) 
    {
        if (i == st && i == ed)
        {
            mn[p] = mx[p] = x;
            ans[p] = 0;
            return ;
        }
        int m = st + ed >> 1;
        if (i <= m) update(p << 1,st,m,i,x);
        else update(p << 1 | 1,m + 1,ed,i,x);
        up(p,ed - st + 1);
    };
    void build(int p,int st,int ed,vt& a)
    {
        if (st == ed) 
        {
            mx[p] = mn[p] = a[st];
            ans[p] = 0;
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p,ed - st + 1);
    }
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return ans[p];
        }
        int m = st + ed >> 1;
        int res = 0;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res; 
    };
public:
    segtree(vt& a) 
    {
        n = a.size();
        mx.assign(n << 2,0);
        mn.assign(n << 2,0);
        ans.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int id,int x) 
    {
        update(1,0,n - 1,id,x);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    int N = 1;
    while (N < n) N <<= 1;
    vt a(N,1e9);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    cout << tr.query(0,N - 1) << endl;
    while (q--)
    {
        int i,x;
        cin >> i >> x;
        tr.update(i,x);
        cout << tr.query(0,N - 1) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}