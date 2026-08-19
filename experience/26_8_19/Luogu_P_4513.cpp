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
    vt mx,pre,suf,sum;
    void up(int p)
    {
        mx[p] = max({mx[p << 1],mx[p << 1 | 1],suf[p << 1] + pre[p << 1 | 1]});
        pre[p] = max(pre[p << 1],sum[p << 1] + pre[p << 1 | 1]);
        suf[p] = max(suf[p << 1 | 1],sum[p << 1 | 1] + suf[p << 1]);
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void build(int p,int st,int ed,vt& a)
    {
        if (st == ed)
        {
            mx[p] = pre[p] = suf[p] = sum[p] = a[st];
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p);
    }
    void update(int p,int st,int ed,int i,int v)
    {
        if (st == ed)
        {
            mx[p] = pre[p] = suf[p] = sum[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (i <= m) update(p << 1,st,m,i,v);
        else update(p << 1 | 1,m + 1,ed,i,v);
        up(p);
    }
    vt query(int p,int st, int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return {mx[p],pre[p],suf[p],sum[p]};
        }
        int m = st + ed >> 1;
        if (r <= m) return query(p << 1,st,m,l,r);
        if (l > m) return query(p << 1 | 1,m + 1,ed,l,r);
        auto L = query(p << 1,st,m,l,r);
        auto R = query(p << 1 | 1,m + 1,ed,l,r);
        vt res(4);
        res[0] = max({L[0],R[0],L[2] + R[1]});
        res[1] = max(L[1],L[3] + R[1]);
        res[2] = max(R[2],R[3] + L[2]);
        res[3] = L[3] + R[3];
        return res;
    }

public:
    segtree (vt& a)
    {
        n = a.size();
        mx.assign(n << 2,INT_MIN / 2);
        pre.assign(n << 2,INT_MIN / 2);
        suf.assign(n << 2,INT_MIN / 2);
        sum.assign(n << 2,INT_MIN / 2);
        build(1,0,n - 1,a);
    }
    void update(int i,int v)
    {
        update(1,0,n - 1,i,v);
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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l,r;
            cin >> l >> r;
            if (l > r) swap(l,r);
            l--;r--;
            cout << tr.query(l,r) << endl;
        }
        else 
        {
            int i,x;
            cin >> i >> x;
            i--;
            tr.update(i,x);
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