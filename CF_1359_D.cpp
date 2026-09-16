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
const int N = (int)1e5 + 9;

struct ty {
    int l, r, mx, sum, f;
}tr[4 * N];
#define ls(x) tr[x].l
#define rs(x) tr[x].r
#define mx(x) tr[x].mx
#define sum(x) tr[x].sum
#define f(x) tr[x].f
void pushup(int x) {
    sum(x) = sum(ls(x)) + sum(rs(x));
    mx(x) = max(mx(ls(x)), mx(rs(x)));
}
void build(int x, int l, int r) {
    if (l == r) {
        mx(x) = -1e9;
        sum(x) = 0;
        f(x) = 0;
        return ;
    }
    int mid = l + (r - l) / 2;
    mx(x) = -1e9;
    sum(x) = 0;
    f(x) = 0;
    ls(x) = x << 1;
    rs(x) = x << 1 | 1;
    build(ls(x), l, mid);
    build(rs(x), mid + 1, r);
    pushup(x);
}
void pushdown(int x, int l, int r) {
    if (f(x)) {
        int v = f(x);
        f(x) = 0;
        f(ls(x)) += v;
        f(rs(x)) += v;
        int mid = l + (r - l) / 2;
        sum(ls(x)) += v * (mid - l + 1);
        sum(rs(x)) += v * (r - l);
        mx(ls(x)) += v;
        mx(rs(x)) += v;
        return ;
    }
}

void add(int x, int l, int r, int al, int ar, int v) {
    if (al <= l && ar >= r) {
        sum(x) += v * (r - l + 1);
        f(x) += v;
        mx(x) += v;
        return ;
    }
    pushdown(x, l, r);
    int mid = l + (r - l) / 2;
    if (mid >= al) {
        add(ls(x), l, mid, al, ar, v);
    }
    if (mid < ar) {
        add(rs(x), mid + 1, r, al, ar, v);
    }
    pushup(x);
}
using  arr2 = array<int, 2>;
arr2 ask(int x, int l, int r, int al, int ar) { 
    if (al <= l && ar >= r) {
        return {sum(x), mx(x)};
    }
    pushdown(x, l, r);
    arr2 ans = {0, (int)-1e9};
    int mid = l + (r - l) / 2;
    if (al <= mid) {
        ans[0] += ask(ls(x), l, mid, al, ar)[0];
        ans[1] = max(ans[1], ask(ls(x), l, mid, al, ar)[1]);
    }
    if (ar > mid) {
        ans[0] += ask(rs(x), mid + 1, r, al, ar)[0];
        ans[1] = max(ans[1], ask(rs(x), mid + 1, r, al, ar)[1]);
    }
    return ans;
}

class SparseTable {
    vector<vector<int>> st_min;
    vector<vector<int>> st_max;

public:
    // 时间复杂度 O(n * log n)
    SparseTable(const vector<int>& nums) {
        size_t n = nums.size();
        int w = bit_width(n);
        st_min.resize(w, vector<int>(n));
        st_max.resize(w, vector<int>(n));

        for (int j = 0; j < n; j++) {
            st_min[0][j] = nums[j];
            st_max[0][j] = nums[j];
        }

        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st_min[i][j] = min(st_min[i - 1][j], st_min[i - 1][j + (1 << (i - 1))]);
                st_max[i][j] = max(st_max[i - 1][j], st_max[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    int query_min(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return min(st_min[k][l], st_min[k][r - (1 << k)]);
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    int query_max(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return max(st_max[k][l], st_max[k][r - (1 << k)]);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int l = 1;
    int sum = 0;
    int mx = -1e9;
    for (int r = 1; r <= n; r++) {
        mx = max(mx, a[r]);
        sum += a[r];
        add(1, 1, n, l, r, sum - mx);
    }    
    SparseTable st(a);
    
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