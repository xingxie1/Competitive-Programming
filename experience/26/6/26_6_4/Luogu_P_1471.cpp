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
    vd sum1,sum2,add;
    void up(int p) 
    {
        sum1[p] = sum1[p << 1] + sum1[p << 1 | 1];
        sum2[p] = sum2[p << 1] + sum2[p << 1 | 1];
    }
    void down(int p,int ll,int lr) 
    {
        if (add[p] != 0) 
        {
            sum2[p << 1] += 2 * add[p] * sum1[p << 1] + ll * add[p] * add[p];
            sum2[p << 1 | 1] += 2 * add[p] * sum1[p << 1 | 1] + lr * add[p] * add[p];
            sum1[p << 1] += add[p] * ll;
            sum1[p << 1 | 1] += add[p] * lr;
            add[p << 1] += add[p];
            add[p << 1 | 1] += add[p];
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,vd& a) 
    {
        if (l == r) 
        {
            sum1[p] = a[l];
            sum2[p] = a[l] * a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r,double v) 
    {
        if (l <= st && r >= ed) 
        {
            sum2[p] += 2 * v * sum1[p] + (ed - st + 1) * v * v;
            sum1[p] += (ed - st + 1) * v;
            add[p] += v;
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    double query_sum2(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return sum2[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        double res = 0;
        if (l <= m) res += query_sum2(p << 1,st,m,l,r);
        if (r > m) res += query_sum2(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
    double query_sum(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return sum1[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        double res = 0;
        if (l <= m) res += query_sum(p << 1,st,m,l,r);
        if (r > m) res += query_sum(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
public: 
    segtree(vd& a) 
    {
        n = a.size();
        sum1.assign(n << 2,0);
        sum2.assign(n << 2,0);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,double v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    double query_sum2(int l,int r) 
    {
        return query_sum2(1,0,n - 1,l,r);
    }
    double query_sum(int l,int r) 
    {
        return query_sum(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vd a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (m--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int l,r;
            double v;
            cin >> l >> r >> v;
            l--;r--;
            tr.update(l,r,v);
        }
        else if (op == 2) 
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            double ans = tr.query_sum(l,r) / (r - l + 1);
            cout << fixed << setprecision(4);
            cout << ans << endl;
        }
        else 
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            double s1 = tr.query_sum(l,r);
            double s2 = tr.query_sum2(l,r);
            int n = r - l + 1;
            double ave = s1 / n;
            double ans = s2 / n - ave * ave;
            cout << fixed << setprecision(4);
            cout << ans << endl;
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