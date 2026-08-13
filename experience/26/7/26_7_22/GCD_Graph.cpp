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
int N = 10000005; // 最大筛到 N
vector<int> primes;// 存储质数
vector<bool> isPrime(N + 1, true); // isPrime[i] = true 表示 i 是质数
vector<int> min_p(N + 1);// i的最小质因子
auto init = []
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; ++i) 
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            min_p[i] = i;
        }
        for (int p : primes) 
        {
            if (1LL * i * p > N) break; 
            isPrime[i * p] = false; // 标记为合数
            min_p[i * p] = p;
            if (i % p == 0) break;  // 保证每个合数只被最小质因子筛掉一次
        }
    }
    return 0;   
}();
void solve()
{
    int l,r,n;
    cin >> l >> r >> n;
    vt p;
    int tmp = n;
    while (tmp > 1)
    {
        int pp = min_p[tmp];
        p.push_back(pp);
        while (tmp % pp == 0)
        {
            tmp /= pp;
        }
    }
    int P = n;
    while (!isPrime[P]) P--;
    int m = p.size();
    int R = min(r,P - 1);
    auto f = [&](int l,int r,vt& p)
    {
        ll ans = r - l + 1;
        for (int mask = 1;mask < 1 << m;mask++)
        {
            int cnt = 0;
            ll mul = 1;
            for (int j = 0;j < m;j++)
            {
                if (mask >> j & 1) 
                {
                    cnt++;
                    mul *= p[j];
                }
            }
            if (cnt % 2) ans += (r / mul - (l - 1) / mul);
            else ans -= (r / mul - (l - 1) / mul);
        }
        return ans;
    };
    ll ans = 0;
    if (l <= R) 
    {
        ans = f(l,R,p);
    }
    int L = max(l,P);
    if (L <= r)
    {
        vt dp(n - P + 1,INT_MAX / 2);
        dp[n - P] = 0;
        for (int i = n - 1;i >= P;i--)
        {
            for (int j = i + 1;j <= n;j++)
            {
                dp[i - P] = min(dp[i - P],dp[j - P] + gcd(i,j));
            }
        }
        for (int i = L;i <= r;i++) ans += dp[i - P];
    }
    cout << ans << endl;
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}