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
    vt tr;
    // void up(int p) 
    void down(int p) 
    {
        if (tr[p]) 
        {
            tr[p << 1] = tr[p];
            tr[p << 1 | 1] = tr[p];
            tr[p] = 0;
        }
    }
    void build(int p,int l,int r,const vt& a)
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
    }
    void update(int p,int st,int ed, int l,int r,int x) 
    {
        if (l <= st && r >= ed) 
        {
            tr[p] = x;
            return ;
        }
        int m = st + ed >> 1;
        down(p);
        if (l <= m) update(p << 1,st,m,l,r,x);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,x);
        if (tr[p << 1] == tr[p << 1 | 1]) tr[p] = tr[p << 1];
        else tr[p] = 0;
    }
    void query(int p,int st,int ed,set<int>& set) 
    {
        if (tr[p]) 
        {
            set.insert(tr[p]);
            return ;
        }
        if (st == ed) return ;
        int m = st + ed >> 1;
        query(p << 1,st,m,set);
        query(p << 1 | 1,m + 1,ed,set);
    }
public:
    segtree (const vt& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,int x) 
    {
        update(1,0,n - 1,l,r,x);
    }
    int query() 
    {
        set<int> st;
        query(1,0,n - 1,st);
        return st.size();
    }
};
 void solve()
{
    int n,m;
    cin >> n >> m;
    vt tmp;
    vpii a(m);
    for (int i = 0;i < m;i++) 
    {
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
        tmp.push_back(x);
        tmp.push_back(y + 1);
    }
    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    vt b(tmp.size());
    segtree tr(b);
    int id = 1;
    for (auto&[x,y] : a) 
    {
        x = ranges::lower_bound(tmp,x) - tmp.begin();
        y = ranges::lower_bound(tmp,y + 1) - tmp.begin() - 1;
        tr.update(x,y,id++);
    }
    cout << tr.query() << endl;
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