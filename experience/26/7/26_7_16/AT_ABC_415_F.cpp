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
    struct node
    {
        int len = 0,pre = 0,suf = 0,mx = 0;
        char lc = 0,rc = 0;
    };
    vector<node> tr;
    node merge(node& L,node& R)
    {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        node res;
        res.len = L.len + R.len;
        res.lc = L.lc;
        res.rc = R.rc;
        res.pre = L.pre;
        res.suf = R.suf;
        res.mx = max(L.mx,R.mx);
        if (L.rc == R.lc) 
        {
            res.mx = max(res.mx,L.suf + R.pre);
            if (L.pre == L.len) res.pre = L.len + R.pre;
            if (R.suf == R.len) res.suf = R.len + L.suf;
        }
        return res;
    }
    void build(int p,int st,int ed,string& s) 
    {
        if (st == ed) 
        {
            tr[p].lc = tr[p].rc = s[st];
            tr[p].len = tr[p].mx = tr[p].pre = tr[p].suf = 1;
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,s);
        build(p << 1 | 1,m + 1,ed,s);
        tr[p] = merge(tr[p << 1],tr[p << 1 | 1]);
    }
    void update(int p,int st,int ed,int id,char c) 
    {
        if (st == ed && st == id) 
        {
            tr[p].lc = tr[p].rc = c;
            tr[p].len = tr[p].mx = tr[p].pre = tr[p].suf = 1;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,c);
        else update(p << 1 | 1,m + 1,ed,id,c);
        tr[p] = merge(tr[p << 1],tr[p << 1 | 1]);
    }
    node query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed) 
        {
            return tr[p];
        }
        int m = st + ed >> 1;
        if (r <= m) return query(p << 1,st,m,l,r);
        if (l > m) return query(p << 1 | 1,m + 1,ed,l,r);
        auto L = query(p << 1,st,m,l,r);
        auto R = query(p << 1 | 1,m + 1,ed,l,r);
        return merge(L,R);
    }
public:
    segtree(string& s) 
    {
        n = s.size();
        tr.resize(n << 2);
        build(1,0,n - 1,s);
    }
    void update(int id,char c)
    {
        update(1,0,n - 1,id,c);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r).mx;
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    segtree tr(s);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int id;
            char c;
            cin >> id >> c;
            id--;
            tr.update(id,c);
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