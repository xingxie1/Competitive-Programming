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

int N = 1005; // 最大筛到 N
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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt tmp = a;
    ranges::sort(tmp);
    if (a == tmp) 
    {
        cout << "Bob" << endl;
        return ;
    }
    vvt b(n);
    int cnt = 0;
    for (int i = 0;i < n;i++) 
    {
        int x = a[i];
        if (x == 1) 
        {
            b[i].push_back(x);
            continue;
        }
        for (int p : primes) 
        {
            if (x % p == 0) 
            {
                b[i].push_back(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) b[i].push_back(x);
        if (b[i].size() > 1) cnt++;
    }
    if (cnt >= 1) 
    {
        cout << "Alice" << endl;
        return ;
    }
    vt c;
    for (int i = 0;i < n;i++) 
    {
        for (int x : b[i]) c.push_back(x);
    }
    tmp = c;
    ranges::sort(tmp);
    // for (int x : c) cout << x << " ";
    // cout << endl;
    if (c == tmp) cout << "Bob" << endl;
    else cout << "Alice" << endl;
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