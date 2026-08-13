#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
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
    int n;
    ll k;
    cin >> n >> k;
    Matrix a(n,n);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++) cin >> a[i][j];
    }
    Matrix b = qpow(a,k);
    ll ans = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++) 
        {
            ans = (ans + b[i][j]) % MOD;
        }
    }
    cout << ans << endl;
    

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