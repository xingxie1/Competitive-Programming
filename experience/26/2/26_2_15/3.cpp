#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

int N = 500000; // 最大筛到 N
vector<int> primes;// 存储质数
vector<bool> isPrime(N + 1, true); // isPrime[i] = true 表示 i 是质数
auto init = [] 
{
    isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i <= N; ++i) 
    {
        if (isPrime[i]) primes.push_back(i);
        for (int p : primes) 
        {
            if (1LL * i * p > N) break; 
            isPrime[i * p] = false; // 标记为合数
            if (i % p == 0) break;  // 保证每个合数只被最小质因子筛掉一次
        }
    }
    return 0;
}();
void solve()
{
    // int n;
    // cin >> n;
    // if (n == 1)
    // {
    //     cout << "YES" << endl;
    //     cout << 1 << endl;
    //     return ;
    // }
    // vt a(n);
    // set<int> s;
    // auto it = ranges::upper_bound(primes,n);
    // it--;
    // int x = *it;
    // s.insert(x);
    // s.insert(1);
    // a[0] = x;
    // a[1] = 1;
    // ll sum = x + 1;
    // for (int i = 2;i < n;i++)
    // {
    //     int mn = INT_MAX;
    //     for (int j = 1;j <= sqrt(sum);j++)
    //     {
    //         if (j > n) break;
    //         if (sum % j == 0)
    //         {
    //             if (!s.contains(j)) 
    //             {
    //                 mn = min(mn,j);
    //                 break;
    //             }
    //             if (sum / j <= n && !s.contains(sum / j))
    //             {
    //                 mn = min(1LL * mn,sum / j);
    //             }
    //         }            
    //     }
    //     if (mn == INT_MAX)
    //     {
    //         cout << "NO" << endl;
    //         return ;
    //     }
    //     a[i] = mn;
    //     sum += mn;
    //     s.insert(mn);
    // }
    // cout << "YES" << endl;
    // for (int x : a) cout << x << " ";
    // cout << endl;
    // vt a = {1,2,3,4,5,6};
    // do{
    //     int s = 0,flag = 1;
    //     for (int i = 0;i < a.size();i++)
    //     {
    //         s += a[i];
    //         if (s % a[i]) flag = 0;
    //     }
    //     if (flag)
    //     {
    //         for (int x : a) cout << x << " ";
    //         cout << endl;
    //     }
    // }while (next_permutation(a.begin(),a.end()));

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