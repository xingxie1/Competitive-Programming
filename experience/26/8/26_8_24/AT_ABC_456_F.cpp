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

const ll INF = (1LL << 62);
// min-plus 矩阵
struct Matrix {
    int n, m;              // n 行 m 列
    vector<vector<ll>> a;  // 矩阵元素

    /*
    min-plus 矩阵默认初始化为 INF。

    因为进行转移时：
    c[i][j] = min(c[i][j], a[i][k] + b[k][j])

    所以 c[i][j] 的初始值必须是 INF。
    */
    Matrix(int n = 0, int m = 0, ll value = INF)
        : n(n), m(m), a(n, vector<ll>(m, value)) {}

    /*
    min-plus 单位矩阵：

    对角线为 0，其他位置为 INF。

    它表示：
    从 i 到 i 恰好走 0 步，代价为 0；
    从 i 到其他位置走 0 步，不可达。
    */
    static Matrix identity(int n) {
        Matrix res(n, n);

        for (int i = 0; i < n; i++) {
            res[i][i] = 0;
        }

        return res;
    }

    // 方便使用 mat[i][j]
    vector<ll>& operator[](int i) {
        return a[i];
    }

    const vector<ll>& operator[](int i) const {
        return a[i];
    }

    /*
    min-plus 矩阵乘法。

    当前矩阵：n * m
    b 矩阵：m * b.m
    结果矩阵：n * b.m

    普通矩阵：
    c[i][j] += a[i][k] * b[k][j]

    min-plus 矩阵：
    c[i][j] = min(c[i][j], a[i][k] + b[k][j])
    */
    Matrix operator*(const Matrix& b) const {
        assert(m == b.n);

        Matrix c(n, b.m);

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                // i 到 k 不可达
                if (a[i][k] == INF) {
                    continue;
                }

                for (int j = 0; j < b.m; j++) {
                    // k 到 j 不可达
                    if (b[k][j] == INF) {
                        continue;
                    }

                    c[i][j] = min(
                        c[i][j],
                        a[i][k] + b[k][j]
                    );
                }
            }
        }

        return c;
    }
};

// min-plus 矩阵快速幂
// 返回 a^k
// 要求 a 是方阵
Matrix qpow(Matrix a, ll k) {
    assert(a.n == a.m);

    Matrix res = Matrix::identity(a.n);

    while (k > 0) {
        if (k & 1LL) {
            res = res * a;
        }

        a = a * a;
        k >>= 1LL;
    }

    return res;
}

/*
计算 a^k * f0。

常用于：

dp[t] = a * dp[t - 1]

那么：

dp[k] = a^k * dp[0]

f0 一般是列向量。
*/
Matrix powMul(Matrix a, ll k, Matrix f0) {
    assert(a.n == a.m);
    assert(a.m == f0.n);

    Matrix res = f0;

    while (k > 0) {
        if (k & 1LL) {
            res = a * res;
        }

        a = a * a;
        k >>= 1LL;
    }

    return res;
}

class segtree
{
    int n;
    vector<Matrix> tr;
    void up(int p)
    {
        tr[p] = tr[p << 1 | 1] * tr[p << 1];
    }
    void build(int p,int l,int r,vll& a)
    {
        if (l == r) 
        {
            Matrix mat(2,2);
            mat[0] = {LLONG_MAX / 2,0};
            mat[1] = {a[l],a[l]};
            tr[p] = mat;
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    Matrix query(int p,int st,int ed,int l,int r)
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
        return R * L;
    }
public:
    segtree (vll& a) 
    {
        n = a.size() - 1;
        tr.assign(n << 2,Matrix(2,2));
        build(1,1,n,a);
    }
    Matrix query(int l,int r)
    {
        return query(1,1,n,l,r);
    }
    
};
void solve()
{
    int n,k;
    cin >> n >> k;
    vll a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    a[0] = LLONG_MAX / 2;
    segtree tr(a);
    ll ans = LLONG_MAX / 2;
    for (int l = 1;l + k - 1 <= n;l++) 
    {
        int r = l + k - 1;
        Matrix mat = tr.query(l,r);
        Matrix f(2,1);
        f[0][0] = 0;
        f[1][0] = a[l - 1];
        Matrix res = mat * f;
        ans = min(ans,res[1][0]);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}