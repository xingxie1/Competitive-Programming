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
    vt mx,len,pre,suf,isu,upd;
    void up(int p)
    {
        len[p] = len[p << 1] + len[p << 1 | 1];
        pre[p] = pre[p << 1];
        suf[p] = suf[p << 1 | 1];
        mx[p] = max({mx[p << 1],mx[p << 1 | 1],suf[p << 1] + pre[p << 1 | 1]});
        if (pre[p << 1] == len[p << 1])
        {
            pre[p] += pre[p << 1 | 1];
        }
        if (pre[p << 1 | 1] == len[p << 1 | 1])
        {
            suf[p] += suf[p << 1];
        }
    }
    void build(int p,int st,int ed)
    {
        if (st == ed)
        {
            mx[p] = len[p] = pre[p] = suf[p] = 1;
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m);
        build(p << 1 | 1,m + 1,ed);
        up(p);
    }
    void apply(int p,int v)
    {
        mx[p] = pre[p] = suf[p] = len[p] * (!v);
        isu[p] = 1;
        upd[p] = v;
    }
    void down(int p)
    {
        if (isu[p])
        {
            apply(p << 1,upd[p]);
            apply(p << 1 | 1,upd[p]);
            isu[p] = 0;
        }
    }
    void update(int p,int st,int ed,int l,int r,int v)
    {
        if (l <= st && r >= ed)
        {
            apply(p,v);
            return ;
        }
        down(p);
        int m = st + ed >> 1;
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    vt query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return {mx[p],pre[p],suf[p],len[p]};
        }
        down(p);
        int m = st + ed >> 1;
        if (r <= m) return query(p << 1,st,m,l,r);
        if (l > m) return query(p << 1 | 1,m + 1,ed,l,r);
        auto L = query(p << 1,st,m,l,r);
        auto R = query(p << 1 | 1,m + 1,ed,l,r);
        vt res(4);
        res[0] = max({L[0],R[0],L[2] + R[1]});
        res[1] = L[1];
        res[2] = R[2];
        res[3] = L[3] + R[3];
        if (L[1] == L[3]) 
        {
            res[1] += R[1];
        }
        if (R[1] == R[3]) 
        {
            res[2] += L[2];
        }
        return res;
    }
public:
    segtree(int _n)
    {
        n = _n;
        mx.assign(n << 2,0);
        len.assign(n << 2,0);
        pre.assign(n << 2,0);
        suf.assign(n << 2,0);
        isu.assign(n << 2,0);
        upd.assign(n << 2,0);
        build(1,0,n - 1);
    }
    void update(int l,int r,int v)
    {
        update(1,0,n - 1,l,r,v);
    }
    int query(int l,int r)
    {
        return query(1,0,n - 1,l,r)[0];
    }
    
};
void solve()
{
    int n,q;
    cin >> n >> q;
    segtree tr(n);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            int l = 0,r = n + 1;
            while (l + 1 < r)
            {
                int m = l + r >> 1;
                if (tr.query(0,m) >= x) r = m;
                else l = m;
            }
            if (r == n + 1) 
            {
                cout << 0 << endl;
                continue;
            }
            l = r - x + 1;
            tr.update(l,r,1);
            cout << l + 1 << endl;
        }
        else 
        {
            int l,y;
            cin >> l >> y;
            int r = l + y - 1;
            l--;r--;
            tr.update(l,r,0);
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