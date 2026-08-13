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
int MOD;
class segtree
{
    int n;
    vll tr,add,mul;
    void push_up(int p) {tr[p] = (tr[p << 1] + tr[p << 1 | 1]) % MOD;}
    void apply(int p,int len,ll ADD,ll MUL)
    {
        tr[p] = (tr[p] * MUL % MOD + ADD * len % MOD) % MOD;
        mul[p] = mul[p] * MUL % MOD;
        add[p] = (add[p] * MUL + ADD) % MOD;
    }
    void push_down(int p,int lenl,int lenr) 
    {
        if (add[p] != 0 || mul[p] != 1) 
        {
            apply(p << 1,lenl,add[p],mul[p]);
            apply(p << 1 | 1,lenr,add[p],mul[p]);
            add[p] = 0;
            mul[p] = 1;
        }
    }
    void build(int p,int l,int r,const vll& a) 
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        push_up(p);
    }
    void update_add(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,ed - st + 1,v,1);
            return ;
        }
        int m = st + ed >> 1;
        push_down(p,m - st + 1,ed - m);
        if (l <= m) update_add(p << 1,st,m,l,r,v);
        if (r > m) update_add(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }   
    void update_mul(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,ed - st + 1,0,v);
            return ;
        }
        int m = st + ed >> 1;
        push_down(p,m - st + 1,ed - m);
        if (l <= m) update_mul(p << 1,st,m,l,r,v);
        if (r > m) update_mul(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return tr[p];
        }
        int m = st + ed >> 1;
        ll res = 0;
        push_down(p,m - st + 1,ed - m);
        if (l <= m) res = (res + query(p << 1,st,m,l,r)) % MOD;
        if (r > m) res = (res + query(p << 1 | 1,m + 1,ed,l,r)) % MOD;
        return res % MOD;
    }
public:
    segtree(const vll& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        add.assign(n << 2,0);
        mul.assign(n << 2,1);
        build(1,0,n - 1,a);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
    void update_add(int l,int r,ll v) 
    {
        update_add(1,0,n - 1,l,r,v);
    }
    void update_mul(int l,int r,ll v) 
    {
        update_mul(1,0,n - 1,l,r,v);
    }
};
void solve()
{   
    int n;
    cin >> n >> MOD;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    int q;
    cin >> q;
    while (q--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int l,r;
            ll v;
            cin >> l >> r >> v;
            l--;r--;
            tr.update_mul(l,r,v);
        }
        else if (op == 2) 
        {
            int l,r;
            ll v;
            cin >> l >> r >> v;
            l--;r--;
            tr.update_add(l,r,v);
        }
        else 
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            cout << tr.query(l,r) << endl;
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