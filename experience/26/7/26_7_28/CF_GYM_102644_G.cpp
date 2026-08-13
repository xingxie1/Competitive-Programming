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
const int MOD = (int)1e9+7;

// 矩阵结构体
struct Matrix {
    int n, m;              // n 行 m 列
    vector<vector<ll>> a;  // 矩阵元素

    // 构造 n * m 的零矩阵
    Matrix(int n = 0, int m = 0) : n(n), m(m), a(n, vector<ll>(m, 0)) {}

    // 构造 n * n 的单位矩阵
    // 单位矩阵 I 满足 A * I = A
    static Matrix identity(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) {
            res.a[i][i] = 1;
        }
        return res;
    }

    // 方便用 mat[i][j] 访问元素
    vector<ll>& operator[](int i) {
        return a[i];
    }

    const vector<ll>& operator[](int i) const {
        return a[i];
    }

    // 矩阵乘法
    // 当前矩阵是 n * m
    // b 矩阵是 m * b.m
    // 结果矩阵是 n * b.m
    Matrix operator*(const Matrix& b) const {
        Matrix c(n, b.m);

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                // 如果当前值是 0，可以跳过，略微优化常数
                if (a[i][k] == 0) continue;

                for (int j = 0; j < b.m; j++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return c;
    }
};

// 矩阵快速幂
// 返回 a^k
// 要求 a 是方阵
Matrix qpow(Matrix a, ll k) {
    Matrix res = Matrix::identity(a.n);

    while (k > 0) {
        if (k & 1) {
            res = res * a;
        }

        a = a * a;
        k >>= 1;
    }

    return res;
}

// 计算 A^k * f0
// 常用于线性递推和状态转移
// f0 一般是列向量
Matrix powMul(Matrix a, ll k, Matrix f0) {
    Matrix res = f0;

    while (k > 0) {
        if (k & 1) {
            res = a * res;
        }

        a = a * a;
        k >>= 1;
    }

    return res;
}

void solve()
{
    ll n,k;
    cin >> n >> k;
    vll A(n),c(n);
    for (int i = 0;i < n;i++) cin >> A[i];
    for (int i = 0;i < n;i++) cin >> c[i];
    ll p,q,r;
    cin >> p >> q >> r;
    if (k < n) 
    {
        cout << A[k] << endl;
        return ;
    }
    Matrix a(n + 7,n + 7),f(n + 7,1);
    for (int i = 1;i <= n;i++) f[i][0] = A[n - i];
    ll s = 0;
    for (int i = 1;i <= n;i++) 
    {
        s += c[i - 1] * A[n - i] % MOD;
        s %= MOD;
    }
    s += p + n * q % MOD + n * n * r % MOD;
    s %= MOD;
    f[0][0] = s;
    f[n + 1][0] = p;
    f[n + 2][0] = q;
    f[n + 3][0] = r;
    f[n + 4][0] = n * q % MOD;
    f[n + 5][0] = n * n * r % MOD;
    f[n + 6][0] = 2 * n * r % MOD;
    for (int i = 0;i <= n;i++) 
    {
        if (i == 0) 
        {
            for (int j = 0;j < n;j++) a[i][j] = c[j];
            a[i][n + 1] = 1;//p
            a[i][n + 2] = 1;//q
            a[i][n + 3] = 1;//r
            a[i][n + 4] = 1;//Q = (n + 1) * q;
            a[i][n + 5] = 1;//R1 = (n + 1) * (n + 1) * r
            a[i][n + 6] = 1;//R2 = 2 * (n + 1) * r
        }
        else a[i][i - 1] = 1;
    }
    a[n + 1][n + 1] = 1;
    a[n + 2][n + 2] = 1;
    a[n + 3][n + 3] = 1;
    a[n + 4][n + 4] = 1;
    a[n + 4][n + 2] = 1;
    a[n + 5][n + 3] = 1;
    a[n + 5][n + 5] = 1;
    a[n + 5][n + 6] = 1;
    a[n + 6][n + 6] = 1;
    a[n + 6][n + 3] = 2;
    Matrix res = powMul(a,k - n,f);
    // for (int i = 0;i < 2;i++) cout << res[i][0] << endl;
    cout << res[0][0] << endl;
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