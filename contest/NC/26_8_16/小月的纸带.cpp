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
    vt pre,suf,cnta,cntb,cntc,lazy;
    void up(int p)
    {
        pre[p] = pre[p << 1];
        suf[p] = suf[p << 1 | 1];
        cnta[p] = cnta[p << 1] + cnta[p << 1 | 1];
        cntb[p] = cntb[p << 1] + cntb[p << 1 | 1];
        cntc[p] = cntc[p << 1] + cntc[p << 1 | 1];
        if (suf[p << 1] == pre[p << 1 | 1])
        {
            if (suf[p << 1] == 0) cnta[p]--;
            if (suf[p << 1] == 1) cntb[p]--;
            if (suf[p << 1] == 2) cntc[p]--;
        }
    }
    void build(int p,int st,int ed,string& s)
    {
        if (st == ed)
        {
            pre[p] = s[st] - 'A';
            suf[p] = s[st] - 'A';
            if (s[st] == 'A') cnta[p]++;
            if (s[st] == 'B') cntb[p]++;
            if (s[st] == 'C') cntc[p]++;
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,s);
        build(p << 1 | 1,m + 1,ed,s);
        up(p);
    }
    void apply(int p) 
    {
        pre[p] = (pre[p] + 1) % 3;
        suf[p] = (suf[p] + 1) % 3;
        int tmp = cntc[p];
        cntc[p] = cntb[p];
        cntb[p] = cnta[p];
        cnta[p] = tmp; 
    }
    void down(int p)
    {
        int t = lazy[p];
        lazy[p] = 0;
        while (t--)
        {
            apply(p << 1);
            apply(p << 1 | 1);
            lazy[p << 1]++;
            lazy[p << 1] %= 3;
            lazy[p << 1 | 1]++;
            lazy[p << 1 | 1] %= 3;
        }
    }
    void update(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            apply(p);
            lazy[p] ++;
            lazy[p] %= 3;
            return ;
        }
        int m = st + ed >> 1;
        down(p);
        if (l <= m) update(p << 1,st,m,l,r);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r);
        up(p);
    }

public:
    segtree (string& s)
    {
        n = s.size();
        pre.assign(n << 2,0);
        suf.assign(n << 2,0);
        cnta.assign(n << 2,0);
        cntb.assign(n << 2,0);
        cntc.assign(n << 2,0);
        lazy.assign(n << 2,0);
        build(1,0,n - 1,s);
    }
    int query() 
    {
        return cnta[1];
    }
    void update(int l,int r)
    {
        update(1,0,n - 1,l,r);
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
            int l,r;
            cin >> l >> r;
            l--;r--;
            tr.update(l,r);
        }
        else 
        {
            cout << tr.query() << endl;
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