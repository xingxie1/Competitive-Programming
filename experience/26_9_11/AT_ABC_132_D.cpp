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

// 写像十二相
//
// n 个球放入 k 个盒子
//
// 球：有区别 / 无区别
// 盒：有区别 / 无区别
//
// 限制：
// 1. 每个盒子至多一个
// 2. 每个盒子任意个
// 3. 每个盒子至少一个
struct TwelvefoldWay
{
    // fac[i]  = i!
    // ifac[i] = (i!)^(-1)
    vector<ll> fac{1};
    vector<ll> ifac{1};

    ll qpow(ll a,ll b)
    {
        ll res = 1;
        a %= MOD;

        while(b)
        {
            if(b & 1){
                res = res * a % MOD;
            }

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    // 将阶乘、逆阶乘预处理扩展到 n
    void expand(ll n)
    {
        if(n < (ll)fac.size()) return;

        ll old = (ll)fac.size() - 1;

        fac.resize(n + 1);
        ifac.resize(n + 1);

        for(ll i = old + 1 ; i <= n ; i++){
            fac[i] = fac[i - 1] * i % MOD;
        }

        ifac[n] = qpow(fac[n],MOD - 2);

        for(ll i = n ; i > old ; i--){
            ifac[i - 1] = ifac[i] * i % MOD;
        }
    }

    // n!
    ll F(ll n)
    {
        if(n < 0) return 0;

        expand(n);

        return fac[n];
    }

    // 组合数 C(n,k)
    ll C(ll n,ll k)
    {
        if(n < 0 || k < 0 || k > n) return 0;

        expand(n);

        return fac[n] * ifac[k] % MOD
                      * ifac[n - k] % MOD;
    }

    // 排列数 P(n,k)
    // 从 n 个不同元素中选 k 个并排列
    // P(n,k) = n! / (n-k)!
    ll P(ll n,ll k)
    {
        if(n < 0 || k < 0 || k > n) return 0;

        expand(n);

        return fac[n] * ifac[n - k] % MOD;
    }

    // ============================================================
    // 第二类斯特林数 S(n,k)
    // 含义：
    // 将 n 个不同元素划分成恰好 k 个
    // 非空、无标号集合的方案数
    // 也就是：
    // n 个不同球放入 k 个相同盒子，
    // 每个盒子至少一个
    // 容斥公式：
    // S(n,k)
    // = 1/k! * sum_{i=0}^k (-1)^(k-i) C(k,i) i^n
    // 复杂度：O(k log n)
    // ============================================================
    ll stirling2(ll n,ll k)
    {
        if(k < 0 || k > n) return 0;
        if(n == 0) return k == 0;

        expand(k);

        ll res = 0;

        for(ll i = 0 ; i <= k ; i++)
        {
            ll cur = C(k,i) * qpow(i,n) % MOD;

            if((k - i) & 1){
                res = (res - cur + MOD) % MOD;
            }else{
                res = (res + cur) % MOD;
            }
        }

        return res * ifac[k] % MOD;
    }

    // ============================================================
    // 限制 Bell 数
    // B(n,k) = sum_{i=0}^k S(n,i)
    // 含义：
    // 将 n 个不同元素划分成至多 k 个
    // 非空、无标号集合
    // 也就是：
    // n 个不同球放入最多 k 个相同盒子
    // 复杂度：O(k log n)
    // ============================================================
    ll bell(ll n,ll k)
    {
        if(n < 0 || k < 0) return 0;

        k = min(n,k);

        expand(k);

        vector<ll> pre(k + 2);

        // pre[j] 维护
        // sum_{i=0}^{j-1} (-1)^i / i!
        for(ll j = 0 ; j <= k ; j++)
        {
            ll add = ifac[j];

            if(j & 1){
                pre[j + 1] = (pre[j] - add + MOD) % MOD;
            }else{
                pre[j + 1] = (pre[j] + add) % MOD;
            }
        }

        ll res = 0;

        for(ll i = 0 ; i <= k ; i++)
        {
            ll cur = qpow(i,n) * ifac[i] % MOD;
            cur = cur * pre[k - i + 1] % MOD;

            res = (res + cur) % MOD;
        }

        return res;
    }

    // ============================================================
    // 整数分拆
    // partition(n,k)
    // 表示：
    // 把整数 n 拆成至多 k 个正整数之和，
    // 不考虑顺序
    // 例如：
    // n = 5, k = 2
    // 5
    // 4 + 1
    // 3 + 2
    // 一共 3 种
    // 根据整数分拆的共轭性质：
    // "最多 k 个部分"
    // 等价于
    // "每个部分大小 <= k"
    // 因此可以直接做完全背包
    // 复杂度：O(nk)
    // ============================================================
    ll partition(ll n,ll k)
    {
        if(n < 0 || k < 0) return 0;

        k = min(n,k);

        vector<ll> dp(n + 1);
        dp[0] = 1;

        // 可以使用大小为 1,2,...,k 的数
        for(ll x = 1 ; x <= k ; x++)
        {
            // 完全背包
            for(ll s = x ; s <= n ; s++)
            {
                dp[s] += dp[s - x];

                if(dp[s] >= MOD){
                    dp[s] -= MOD;
                }
            }
        }

        return dp[n];
    }

    // ============================================================
    // 1.
    // 球：不同
    // 盒：不同
    // 限制：每盒至多一个
    // n 个不同球放入 k 个不同盒子
    // 每个盒子最多放一个球
    // 等价于：
    // 从 k 个盒子中给 n 个球选择不同位置
    // 答案：
    // P(k,n)
    // ============================================================
    ll solve1(ll n,ll k)
    {
        return P(k,n);
    }
    // ============================================================
    // 2.
    // 球：不同
    // 盒：不同
    // 限制：任意个
    // 每个球都有 k 种盒子可以选择
    // 答案：
    // k^n
    // ============================================================
    ll solve2(ll n,ll k)
    {
        return qpow(k,n);
    }
    // ============================================================
    // 3.
    // 球：不同
    // 盒：不同
    // 限制：每盒至少一个
    // 即满射
    // 先把 n 个不同球划分成 k 个非空组：
    // S(n,k)
    // 再把 k 个组分配给 k 个不同盒子：
    // k!
    // 答案：
    // k! * S(n,k)
    // ============================================================
    ll solve3(ll n,ll k)
    {
        if(k > n) return 0;

        return F(k) * stirling2(n,k) % MOD;
    }

    // ============================================================
    // 4.
    // 球：相同
    // 盒：不同
    // 限制：每盒至多一个
    // 只需要选择哪 n 个盒子有球
    // 答案：
    // C(k,n)
    // ============================================================
    ll solve4(ll n,ll k)
    {
        return C(k,n);
    }

    // ============================================================
    // 5.
    // 球：相同
    // 盒：不同
    // 限制：任意个
    // 相当于：
    // x1 + x2 + ... + xk = n
    // xi >= 0
    // 隔板法：
    // C(n+k-1,k-1)
    // = C(n+k-1,n)
    // ============================================================
    ll solve5(ll n,ll k)
    {
        if(k == 0) return n == 0;

        return C(n + k - 1,n);
    }

    // ============================================================
    // 6.
    // 球：相同
    // 盒：不同
    // 限制：每盒至少一个
    // 相当于：
    // x1 + x2 + ... + xk = n
    // xi >= 1
    // 隔板法：
    // C(n-1,k-1)
    // ============================================================
    ll solve6(ll n,ll k)
    {
        if(k == 0) return n == 0;
        if(n < k) return 0;

        return C(n - 1,k - 1);
    }

    // ============================================================
    // 7.
    // 球：不同
    // 盒：相同
    // 限制：每盒至多一个
    // 因为盒子完全相同，
    // 只要盒子数量 >= 球的数量即可
    // 答案：
    // [n <= k]
    // ============================================================
    ll solve7(ll n,ll k)
    {
        return n <= k;
    }

    // ============================================================
    // 8.
    // 球：不同
    // 盒：相同
    // 限制：任意个
    // 实际使用的非空盒子数量可以是：
    // 0,1,2,...,k
    // 对于恰好使用 i 个盒子：
    // S(n,i)
    // 答案：
    // sum S(n,i)
    // 即限制 Bell 数
    // ============================================================
    ll solve8(ll n,ll k)
    {
        return bell(n,k);
    }

    // ============================================================
    // 9.
    // 球：不同
    // 盒：相同
    // 限制：每盒至少一个
    // 这就是第二类斯特林数
    // 答案：
    // S(n,k)
    // 竞赛中非常常见：
    // "把 n 个有编号元素分成 k 个非空无标号集合"
    // ============================================================
    ll solve9(ll n,ll k)
    {
        return stirling2(n,k);
    }

    // ============================================================
    // 10.
    // 球：相同
    // 盒：相同
    // 限制：每盒至多一个
    // 因为球和盒子都没有区别，
    // 只要盒子够用即可
    // 答案：
    // [n <= k]
    // ============================================================
    ll solve10(ll n,ll k)
    {
        return n <= k;
    }

    // ============================================================
    // 11.
    // 球：相同
    // 盒：相同
    // 限制：任意个
    // 等价于：
    // 把整数 n 拆成至多 k 个正整数
    // 例如：
    // 5 个相同球放入最多 2 个相同非空盒子
    // 5
    // 4+1
    // 3+2
    // 即整数分拆
    // ============================================================
    ll solve11(ll n,ll k)
    {
        return partition(n,k);
    }

    // ============================================================
    // 12.
    // 球：相同
    // 盒：相同
    // 限制：每盒至少一个
    // 相当于：
    // 把 n 拆成恰好 k 个正整数
    // 先给每个盒子一个球：
    // n -> n-k
    // 然后剩下 n-k 个球放入至多 k 个相同盒子
    // 答案：
    // partition(n-k,k)
    // ============================================================
    ll solve12(ll n,ll k)
    {
        if(n < k) return 0;

        return partition(n - k,k);
    }

    // ============================================================
    // 统一查询接口
    // ballDistinct:
    // true  -> 球有区别
    // false -> 球无区别
    // boxDistinct:
    // true  -> 盒有区别
    // false -> 盒无区别
    // limit:
    // 0 -> 每盒至多一个
    // 1 -> 每盒任意个
    // 2 -> 每盒至少一个
    // 实际比赛更推荐直接使用 solve1 ~ solve12
    // 可读性更好
    // ============================================================
    ll query(
        ll n,
        ll k,
        bool ballDistinct,
        bool boxDistinct,
        int limit
    )
    {
        // 不同球 + 不同盒
        if(ballDistinct && boxDistinct)
        {
            if(limit == 0) return solve1(n,k);
            if(limit == 1) return solve2(n,k);
            return solve3(n,k);
        }

        // 相同球 + 不同盒
        if(!ballDistinct && boxDistinct)
        {
            if(limit == 0) return solve4(n,k);
            if(limit == 1) return solve5(n,k);
            return solve6(n,k);
        }

        // 不同球 + 相同盒
        if(ballDistinct && !boxDistinct)
        {
            if(limit == 0) return solve7(n,k);
            if(limit == 1) return solve8(n,k);
            return solve9(n,k);
        }

        // 相同球 + 相同盒
        if(limit == 0) return solve10(n,k);
        if(limit == 1) return solve11(n,k);
        return solve12(n,k);
    }
};

void solve()
{
    int n,k;
    cin >> n >> k;
    TwelvefoldWay tw;
    for (int i = 1;i <= k;i++)
    {
        // cout << tw.solve6(k,i) << " " << tw.C(n - k + 1,i) << endl;
        ll ans = tw.solve6(k,i) * tw.C(n - k + 1,i) % MOD;
        cout << ans << endl;
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