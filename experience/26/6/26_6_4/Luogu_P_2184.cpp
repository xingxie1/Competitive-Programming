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

// class segtree 
// {
//     int n;
//     vt sum;
//     void up(int p) 
//     {
//         sum[p] = sum[p << 1] + sum[p << 1 | 1];
//     }
//     void build(int p,int l,int r,vt& a) 
//     {
//         if (l == r) 
//         {
//             sum[p] = a[l];
//             return ;
//         }
//         int m = l + r >> 1;
//         build(p << 1,l,m,a);
//         build(p << 1 | 1,m + 1,r,a);
//         up(p);
//     }
//     void update(int p,int st,int ed,int l,int r,int v) 
//     {
//         if (l <= st && r >= ed) 
//         {
//             sum[p] += v;
//             return ;
//         }
//         int m = st + ed >> 1;
//         if (l <= m) update(p << 1,st,m,l,r,v);
//         if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
//         up(p);
//     }
//     int query(int p,int st,int ed,int l,int r) 
//     {
//         if (l <= st && r >= ed) return sum[p];
//         int m = st + ed >> 1;
//         int res = 0;
//         if (l <= m) res += query(p << 1,st,m,l,r);
//         if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
//         return res;
//     }
// public:
//     segtree(vt& a) 
//     {
//         n = a.size();
//         sum.assign(n << 2,0);
//         build(1,0,n - 1,a);
//     }
//     int query(int l,int r) 
//     {
//         return query(1,0,n - 1,l,r);
//     }
//     void update(int l,int r,int v)
//     {
//         update(1,0,n - 1,l,r,v);
//     } 
// };
class FenwickTree 
{
    vt tr;
public:
    void update(int i,int v) 
    {
        for (;i < tr.size();i += i & -i) tr[i] += v;
    } 
    int pre(int i) 
    {
        int res = 0;
        for (;i > 0;i -= i & -i) res += tr[i];
        return res;
    }
    int query(int l,int r) 
    {
        return pre(r) - pre(l - 1);
    }
    FenwickTree(int n) : tr(n + 1) {}
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n + 1);
    FenwickTree tr1(n),tr2(n);
    // segtree tr1(a),tr2(a);
    while (q--) 
    {
        int op,l,r;
        cin >> op >> l >> r;
        if (op == 1) 
        {
            tr1.update(l,1);
            tr2.update(r,1);
        }
        else cout << tr1.query(1,r) - tr2.query(1,l - 1) << endl;
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