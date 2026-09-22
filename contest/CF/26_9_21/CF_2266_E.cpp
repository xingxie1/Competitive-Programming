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

int N = 200005; // 最大筛到 N
vector<int> primes;// 存储质数
vector<bool> isPrime(N + 1, true); // isPrime[i] = true 表示 i 是质数
vector<int> max_p(N + 1);// i的最大质因子
vvt p(N + 1);
auto init = [] 
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= N; ++i) 
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            p[i].push_back(i);
        }
        for (int p : primes) 
        {
            if (1LL * i * p > N) break; 
            isPrime[i * p] = false;
            if (i % p == 0) break;  // 保证每个合数只被最小质因子筛掉一次
        }
    }
    for (int x = 4;x <= N;x++)
    {
        for (int pp = 2;pp <= sqrt(x);pp++)
        {
            if (x % pp == 0) 
            {
                if (isPrime[pp]) p[x].push_back(pp);
                if (isPrime[x / pp]) p[x].push_back(pp);
            }
        }
        ranges::sort(p[x]);
        p[x].erase(unique(p[x].begin(),p[x].end()),p[x].end());
    }
    return 0;
}();

void solve()
{
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        int cnt = 1;
        for (int pp : p[x])
        {
            
        }
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