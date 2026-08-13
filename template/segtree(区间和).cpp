#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class segtree
{
private:
    vector<ll> tr;
    vector<ll> add;
    int n;
    void up(int p)
    {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    void down(int p,int lenl,int lenr)
    {
        if (add[p] != 0)
        {
            add[p << 1] += add[p];
            add[p << 1 | 1] += add[p];
            tr[p << 1] += add[p] * lenl;
            tr[p << 1 | 1] += add[p] * lenr;
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,const vector<ll>& a)
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return ;
        }
        int m = l + (r - l) / 2;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    //区间[l,r]加上v
    void update(int p,int start,int end,int l,int r,ll v)
    {
        if (l <= start && end <= r) 
        {
            tr[p] += v * (end - start + 1);
            add[p] += v;
            return ;
        }
        int m = start + (end - start) / 2;
        down(p,m - start + 1,end - m);
        if (l <= m) update(p << 1,start,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,end,l,r,v);
        up(p);
    }
    ll query(int p,int start,int end,int l,int r)
    {
        if (l <= start && end <= r) return tr[p];
        int m = start + (end - start) / 2;
        down(p,m - start + 1,end - m);

        ll res = 0;
        if (l <= m) res += query(p << 1,start,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,end,l,r);

        return res;
    }
public:
    segtree(const vector<ll>& a) 
    {
        n = a.size();
        tr.assign(4 * n,0);
        add.assign(4 * n,0);
        if (n > 0) 
        {
            build(1,0,n - 1,a);
        }
    }
    //区间[l,r]加v
    void update(int l,int r,ll v)
    {
        if (l <= r && l >= 0 && r < n) 
        {
            update(1,0,n - 1,l,r,v);
        }
    }
    //查询区间[l,r] 的和(下标0开始)
    ll query(int l,int r)
    {
        if (l <= r && l >= 0 && r < n) 
        {
            return query(1,0,n - 1,l,r);
        }
        return 0;
    }
};
