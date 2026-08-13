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
using i128 = __int128_t;
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

//找到一组x,y使得ax + by = g
//g等于gcd(a,b)
i128 exgcd(i128 a,i128 b,i128 &x,i128 &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    i128 x1,y1;
    i128 g = exgcd(b,a % b,x1,y1);

    x = y1;
    y = x1 - a / b * y1;

    return g;
}

//求a在模m的逆元
//前提gcd(a,m) = 1
ll inv(ll a,ll mod)
{
    i128 x,y;
    i128 g = exgcd(a,mod,x,y);

    if (g != 1) return -1;

    return (ll)((x % mod + mod) % mod);
}

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    ll L = 1;
    int mx = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        mx = max(mx,a[i]);
        L = lcm(L,a[i]);
    }
    map<int,int> cnt;
    for (int x : a)
    {
        while (x > 1)
        {
            int p = min_p[x];
            int cc = 0;
            while (x % p == 0)
            {
                x /= p;
                cc++;
            }
            cnt[p] = max(cnt[p],cc);
        }
    }
    vll b;
    cnt[2]++;
    for (auto& [x,c] : cnt)
    {
        b.push_back(pow(x,c));
    }
    int m = b.size();
    ll N = 2 * L;
    ll ans = N;
    for (int mask = 0;mask < 1 << m;mask++)
    {
        ll A = 1;
        for (int i = 0;i < m;i++) 
        {
            if (mask >> i & 1) A *= b[i];
        }
        ll B = N / A;
        ll cur;
        if (B == 1) cur = N;
        else 
        {
            i128 x,y;
            exgcd(A,B,x,y);
            ll inv = (x % B + B) % B;
            ll t = (B - inv) % B;
            ll m = A * t;
            cur = (i128)A * t;
            if (cur == 0) cur = N;
        }
        ans = min(ans,cur);
    }
    cout << ans << endl;
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