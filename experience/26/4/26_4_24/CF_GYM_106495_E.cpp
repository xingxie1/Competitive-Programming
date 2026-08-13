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
    int n,q;
    cin >> n >> q;
    vvt a(n);
    for (int i = 2;i <= n;i++)
    {
        int x = i;
        while (x > 1)
        {
            a[i - 1].push_back(min_p[x]);
            x /= min_p[x];
        }
    }
    ranges::sort(a);
    vt sum(n);
    for (int i = 0;i < n;i++)
    {
        int s = 1;
        for (int x : a[i]) s *= x;
        sum[i] = s;
    }
    while (q--)
    {
        int x;
        cin >> x;
        cout << sum[x - 1] << endl;
    }
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
