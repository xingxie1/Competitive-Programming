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
    vt cnt,pre0,pre1,len0,len1,suf0,suf1;
    vt upd,isu,rev,isr;
private:
    void up(int p,int ln,int rn) 
    {
        cnt[p] = cnt[p << 1] + cnt[p << 1 | 1];
        len0[p] = max({len0[p << 1],len0[p << 1 | 1],suf0[p << 1] + pre0[p << 1 | 1]});
        len1[p] = max({len1[p << 1],len1[p << 1 | 1],suf1[p << 1] + pre1[p << 1 | 1]});
        pre0[p] = pre0[p << 1] == ln ? pre0[p << 1] + pre0[p << 1 | 1] : pre0[p << 1];
        pre1[p] = pre1[p << 1] == ln ? pre1[p << 1] + pre1[p << 1 | 1] : pre1[p << 1];
        suf0[p] = suf0[p << 1 | 1] == rn ? suf0[p << 1 | 1] + suf0[p << 1] : suf0[p << 1 | 1];
        suf1[p] = suf1[p << 1 | 1] == rn ? suf1[p << 1 | 1] + suf1[p << 1] : suf1[p << 1 | 1];
    }
    void apply_update(int p,int len,int v)
    {
        cnt[p] = len * v;
        len0[p] = pre0[p] = suf0[p] = (v == 0 ? len : 0);
        len1[p] = pre1[p] = suf1[p] = (v == 1 ? len : 0);

        upd[p] = v;
        isu[p] = 1;
        isr[p] = 0;
    }
    void apply_reverse(int p,int len) 
    {
        cnt[p] = len - cnt[p];
        swap(len0[p],len1[p]);
        swap(pre0[p],pre1[p]);
        swap(suf0[p],suf1[p]);
        isr[p] = !isr[p];
    }
    void down(int p,int st,int ed) 
    {
        int m = st + ed >> 1;
        if (isu[p]) 
        {
            apply_update(p << 1,m - st + 1,upd[p]);
            apply_update(p << 1 | 1,ed - m,upd[p]);
            isu[p] = 0;
        }
        if (isr[p]) 
        {
            apply_reverse(p << 1,m - st + 1);
            apply_reverse(p << 1 | 1,ed - m);
            isr[p] = 0;
        }
    }
    void build(int p,int l,int r,vt& a) 
    {
        if (l == r) 
        {
            cnt[p] = a[l] == 1;
            pre1[p] = len1[p] = suf1[p] = a[l] == 1;
            pre0[p] = len0[p] = suf0[p] = a[l] == 0;
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p,m - l + 1,r - m);
    }
    void update(int p,int st,int ed,int l,int r,int v) 
    {
        if (l <= st && r >= ed) 
        {
            apply_update(p,ed - st + 1,v);
            return ;
        }
        down(p,st,ed);
        int m = st + ed >> 1;
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p,m - st + 1,ed - m);
    }
    
    void reverse(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            apply_reverse(p,ed - st + 1);
            return ;    
        }
        down(p,st,ed);
        int m = st + ed >> 1;
        if (l <= m) reverse(p << 1,st,m,l,r);
        if (r > m) reverse(p << 1 | 1,m + 1,ed,l,r);
        up(p,m - st + 1,ed - m);
    }
    
    int query_sum(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return cnt[p];
        int m = st + ed >> 1;
        int res = 0;
        down(p,st,ed);
        if (l <= m) res += query_sum(p << 1,st,m,l,r);
        if (r > m) res += query_sum(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
    //最长1,前缀1,后缀1,区间长度
    vt query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return {len1[p],pre1[p],suf1[p],ed - st + 1};
        }
        down(p,st,ed);
        int m = st + ed >> 1;
        if (r <= m) return query(p << 1,st,m,l,r);
        if (l > m) return query(p << 1 | 1,m + 1,ed,l,r);
        auto L = query(p << 1,st,m,l,r);
        auto R = query(p << 1 | 1,m + 1,ed,l,r);
        vt res (4);
        int lbest = L[0],lpre = L[1],lsuf = L[2],ll = L[3];
        int rbest = R[0],rpre = R[1],rsuf = R[2],lr = R[3];
        res[3] = ll + lr;
        if (lpre == ll) res[1] = lpre + rpre;
        else res[1] = lpre;
        if (rsuf == lr) res[2] = rsuf + lsuf; 
        else res[2] = rsuf;
        res[0] = max({lbest,rbest,lsuf + rpre});
        return res;
    }

public:
    segtree(vt& a) 
    {
        n = a.size();
        cnt.assign(n << 2,0);
        pre0.assign(n << 2,0);
        pre1.assign(n << 2,0);
        len0.assign(n << 2,0);
        len1.assign(n << 2,0);
        suf0.assign(n << 2,0);
        suf1.assign(n << 2,0);
        upd.assign(n << 2,0);
        isu.assign(n << 2,0);
        rev.assign(n << 2,0);
        isr.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r)[0];
    } 
    int query_sum(int l,int r) 
    {
        return query_sum(1,0,n - 1,l,r);
    }

    void update(int l,int r,int v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    void reverse(int l,int r) 
    {
        reverse(1,0,n - 1,l,r);
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
        int l,r;
        cin >> op >> l >> r;
        if (op == 0) 
        {
            tr.update(l,r,0);
        }
        else if (op == 1) tr.update(l,r,1);
        else if (op == 2) tr.reverse(l,r);
        else if (op == 3) cout << tr.query_sum(l,r) << endl;
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