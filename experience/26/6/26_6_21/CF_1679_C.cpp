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

class segtree 
{
    int n;
    vt sum,mn,add;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
    }
    void build(int p,int l,int r,vt& a) 
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
    void update(int p,int st,int ed,int l,int r,int v) 
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
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return mn[p];
        int m = st + ed >> 1;
        int res = INT_MAX;
        down(p,m - st + 1,ed - m);
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(vt& a) 
    {
        n = a.size();
        sum.assign(n << 2,0);
        add.assign(n << 2,0);
        mn.assign(n << 2,INT_MAX / 2);
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
    int n,q;
    cin >> n >> q;
    vt a(n);
    segtree tr1(a),tr2(a);
    while (q--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int x,y;
            cin >> x >> y;
            x--;y--;
            tr1.update(x,x,1);
            tr2.update(y,y,1);
        }
        else if (op == 2) 
        {
            int x,y;
            cin >> x >> y;
            x--;y--;
            tr1.update(x,x,-1);
            tr2.update(y,y,-1);
        }
        else 
        {
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;y1--;x2--;y2--;
            // cout << tr1.query(x1,x2) << "  " << tr2.query(y1,y2) << endl;
            if (tr1.query(x1,x2) > 0 || tr2.query(y1,y2) > 0) YES;
            else NO;
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