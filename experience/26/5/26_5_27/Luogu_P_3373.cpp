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
ll MOD;

class segtree{ 
    vll tr,add,mul;
    int n;
    void push_up(int p) {tr[p] = (tr[p << 1] + tr[p << 1 | 1]) % MOD;};
    void apply(int p,int len,ll MUL,ll ADD)
    {
        tr[p] = (tr[p] * MUL % MOD + ADD * len % MOD) % MOD;
        mul[p] = mul[p] * MUL % MOD;
        add[p] = (add[p] * MUL + ADD) % MOD;
    }
    void push_donw(int p,int lenl,int lenr) 
    {
        if (add[p] != 0 || mul[p] != 1) 
        {
            apply(p << 1,lenl,mul[p],add[p]);
            apply(p << 1 | 1,lenr,mul[p],add[p]);

            mul[p] = 1;
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,const vll& a)
    {
        if (l == r) 
        {
            tr[p] = a[l] % MOD;
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
            apply(p,ed - st + 1,1,v);
            return ;
        }
        int m = st + ed >> 1;
        push_donw(p,m - st + 1,ed - m);
        if (l <= m) update_add(p << 1,st,m,l,r,v);
        if (r > m) update_add(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }
    void update_mul(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,ed - st + 1,v,0);
            return ;
        }
        int m = st + ed >> 1;
        push_donw(p,m - st + 1,ed - m);
        if (l <= m) update_mul(p << 1,st,m,l,r,v);
        if (r > m) update_mul(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p] % MOD;
        int m = st + ed >> 1;
        ll res = 0;
        push_donw(p,m - st + 1,ed - m);
        if (l <= m) res += query(p << 1,st,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
        return res % MOD;
    }
public:
    segtree(const vll& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        add.assign(n << 2,0);
        mul.assign(n << 2,1);
        if (n > 0) build(1,0,n - 1,a);
    }
    void update_add(int l,int r,ll v) 
    {
        if (l <= r && l >= 0 && r < n) update_add(1,0,n - 1,l,r,v);
    }
    void update_mul(int l,int r,ll v) 
    {
        if (l <= r && l >= 0 && r < n) update_mul(1,0,n - 1,l,r,v);
    }
    ll query(int l,int r) 
    {
        if (l <= r && l >= 0 && r < n) return query(1,0,n - 1,l,r);
        return 0;
    }
};
void solve()
{
    int n,q;
    cin >> n >> q >> MOD;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (q--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int x,y,k;
            cin >> x >> y >> k;
            tr.update_mul(x - 1,y - 1,k);
        }
        else if (op == 2) 
        {
            int x,y,k;
            cin >> x >> y >> k;
            tr.update_add(x - 1,y - 1,k);
        }
        else 
        {
            int x,y;
            cin >> x >> y;
            cout << tr.query(x - 1,y - 1) << endl;
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