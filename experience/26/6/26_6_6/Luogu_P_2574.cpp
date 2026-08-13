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

class segtree 
{
    int n;
    vt tr,isset;
    void up(int p) 
    {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    void down(int p,int ll,int lr) 
    {
        if (isset[p]) 
        {
            tr[p << 1] = ll - tr[p << 1];
            tr[p << 1 | 1] = lr - tr[p << 1 | 1];  
            isset[p << 1] ^= 1;
            isset[p << 1 | 1] ^= 1;
            isset[p] = 0;
        }
    }
    void build(int p,int st,int ed,vt& a)  
    {
        if (st == ed) 
        {
            tr[p] = a[st];
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            tr[p] = ed - st + 1 - tr[p];
            isset[p] ^= 1;
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r);
        up(p);
    } 
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return tr[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        int res = 0;
        if (l <= m) res += query(p << 1,st,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
public:
    segtree(vt& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        isset.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r) 
    {
        update(1,0,n - 1,l,r);
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
    string s;
    cin >> s;
    vt a(n);
    for (int i = 0;i < n;i++) if (s[i] == '1') a[i] = 1;
    segtree tr(a);
    while (q--) 
    {
        int op;
        cin >> op;
        int l,r;
        cin >> l >> r;
        l--;r--;
        if (op == 0) 
        {
            tr.update(l,r);
        }
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