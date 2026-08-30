#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define endl '\n'

int N = 100005; // 最大筛到 N
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
    int MOD = 7;
    int m = 1e4;
    vt ans;
    for (int g = 0;g <= m;g++)
    {
        int x = g ^ (MOD - 1);
        if (x % MOD == 1) 
        {
            ans.push_back(g);
        }
    }
    // cout << ans[0] << endl;
    // cout << ans.size() << endl;
    ll sum = 0;
    // for (int i = 0;i < ans.size();i++) 
    // {
    //     cout << ans[i] << " ";
    //     if (i % 16 == 15) cout << endl;
    // }
    for (int i = 1;i < ans.size();i++)
    {
        sum += ans[i] - ans[i - 1];
        cout << ans[i] - ans[i - 1] << " ";
        if (i % 8 == 0) cout << endl;
        // if (i % 16 == 0) break;
    }
    // cout << sum << endl;
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

}