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

int N = 1000005; // 最大筛到 N
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
    int x,y,k;
    cin >> x >> y >> k;
    map<int,int> c1,c2;
    while (x > 1) 
    {
        int p = min_p[x];
        x /= p;
        c1[p]++;
    }
    while (y > 1) 
    {
        int p = min_p[y];
        y /= p;
        c2[p]++;
    }
    vt a,b;
    for (auto& [xx,c] : c1) 
    {
        if (!c2.contains(xx) || c > c2[xx]) 
        {
            if (xx > k) 
            {
                cout << -1 << endl;
                return ;
            }
            for (int i = 0;i < c - c2[xx];i++) a.push_back(xx);
        }
    }
    for (auto& [xx,c] : c2) 
    {
        if (!c1.contains(xx) || c1[xx] < c) 
        {
            if (xx > k)
            {
                cout << -1 << endl;
                return ;
            }
            for (int i = 0;i < c - c1[xx];i++) b.push_back(xx);
        }
    }
    ll A = 1,B = 1;
    for (int x : a) A *= x;
    for (int x : b) B *= x;
    auto f = [&](ll x)
    {
        vt a;
        for (int i = 1;1LL * i * i <= x;i++) 
        {
            if (x % i) continue;
            a.push_back(i);
            if (i != x / i) a.push_back(x / i);
        }
        ranges::sort(a);
        int m = a.size();
        vt dp(m,1e9);
        dp[0] = 0;
        for (int i = 0;i < m;i++) 
        {
            for (int j = 0;j < i;j++)
            {
                if (a[i] % a[j] == 0) 
                {
                    int t = a[i] / a[j];
                    if (t > k) continue;
                    dp[i] = min(dp[i],dp[j] + 1);
                }
            }
        }
        return dp[m - 1];
    };
    int ans = f(A) + f(B);
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