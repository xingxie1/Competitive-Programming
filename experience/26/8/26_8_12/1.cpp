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
    vt mx,pre,suf,fi,la;
    void up(int p,int ll,int lr)
    {
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
        suf[p] = suf[p << 1 | 1];
        pre[p] = pre[p << 1];
        fi[p] = fi[p << 1];
        la[p] = la[p << 1 | 1];
        if (la[p << 1] == fi[p << 1 | 1]) 
        {
            mx[p] = max(mx[p],suf[p << 1] + pre[p << 1 | 1]);
            if (mx[p << 1] == ll)
            {
                pre[p] += pre[p << 1 | 1];
            }
            if (mx[p << 1 | 1] == lr)
            {
                suf[p] += suf[p << 1];
            }
        }
    }
    void build(int p,int l,int r,string& s)
    {
        if (l == r) 
        {
            mx[p] = 1;
            pre[p] = 1;
            suf[p] = 1;
            fi[p] = s[l] - 'a';
            la[p] = s[l] - 'a';
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,s);
        build(p << 1 | 1,m + 1,r,s);
        up(p,m - l + 1,r - m);
    }
    void update(int p,int st,int ed,int id,int v)
    {
        if (st == id && ed == id)
        {
            mx[p] = 1;
            pre[p] = 1;
            suf[p] = 1;
            fi[p] = la[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,v);
        else update(p << 1 | 1,m + 1,ed,id,v);
        up(p,m - st + 1,ed - m);
    }
    vt query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return {mx[p],pre[p],suf[p],fi[p],la[p]};
        }
        int m = st + ed >> 1;
        if (l > m) return query(p << 1 | 1,m + 1,ed,l,r);
        if (r < m) return query(p << 1,st,m,l,r); 
        vt L,R;
        L = query(p << 1,st,m,l,r);
        R = query(p << 1 | 1,m + 1,ed,l,r);
        vt res(5);
        int lmx = L[0],lp = L[1],ls = L[2],lfi = L[3],lla = L[4];
        int rmx = R[0],rp = R[1],rs = R[2],rfi = R[3],rla = R[4];
        res[0] = max(lmx,rmx);
        res[1] = lp;
        res[2] = rs;
        res[3] = lfi;
        res[4] = rla;
        if (la[p << 1] == fi[p << 1 | 1]) 
        {
            res[0] = max(res[0],ls + rp);
            if (mx[p << 1] == m - st + 1)
            {
                res[1] += rp;
            }
            if (mx[p << 1 | 1] == ed - m)
            {
                res[2] += ls;
            }
        }
        return res;
    }
public:
    segtree(string& s)
    {
        n = s.size();
        mx.assign(n << 2,0);
        pre.assign(n << 2,0);
        suf.assign(n << 2,0);
        fi.assign(n << 2,0);
        la.assign(n << 2,0);
        build(1,0,n - 1,s);
    }
    void update(int id,char c)
    {
        update(1,0,n - 1,id,c - 'a');
    }
    int query(int l,int r)
    {
        return query(1,0,n - 1,l,r)[0];
    }
};
void solve()
{
    
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