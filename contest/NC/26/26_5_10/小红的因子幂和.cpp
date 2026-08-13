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
long long qpow(long long a,long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
void solve()
{
    ll x,y;
    cin >> x >> y;
    vt b;
    ll ans = 0;
    auto f = [&](ll x)
    {
        for (int p : primes)
        {
            while (x % p == 0) 
            {
                b.push_back(p);
                x /= p;
            }
        }
        if (x > 1) b.push_back(x);
    };
    f(x);
    f(y);
    int m = b.size();
    set<ll> st;
    for (int i = 0;i < (1LL << m);i++) 
    {
        ll d = 1;
        for (int j = 0;j < m;j++) 
        {
            if (i >> j & 1) 
            {
                d *= b[j];
            }
        }
        if (st.contains(d)) continue;
        st.insert(d);
        ans = (ans + qpow(d % MOD,d)) % MOD;
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