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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int mx = ranges::max(a);
    vt ans;
    vt f(n,1),last(n,-1);
    vt best(mx + 1),id(mx + 1,-1);
    int ansid = 0;
    for (int i = 0;i < n;i++) 
    {
        int x = a[i];
        int t = x;
        while (t != 1) 
        {
            int p = min_p[t];
            int pre = x / p;
            if (id[pre] != -1) 
            {
                int j = id[pre];
                if (f[i] < f[j] + 1) 
                {
                    f[i] = f[j] + 1;
                    last[i] = j;
                }
            }
            while (t % p == 0) t /= p;
        }
        if (f[i] > best[x]) 
        {
            best[x] = f[i];
            id[x] = i;
        }
        if (f[i] > f[ansid]) ansid = i;
    }
    int cur = ansid;
    while (cur != -1) 
    {
        ans.push_back(a[cur]);
        cur = last[cur];
    }
    ranges::reverse(ans);
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
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