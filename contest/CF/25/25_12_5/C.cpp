#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

int isprime(int a)
{
    if (a == 1) return 0;
    for(int i = 2;i <= sqrt(a);i++)
    {
        if (a % i == 0) return 0;
    }
    return 1;
}
void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    unordered_map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int flag = 1;
    for (int i = 1;i <= k;i++)
    {
        if (!cnt.count(i))
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        return ;
    }

    int N = 100000;
    set<int> primes;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; ++i) 
    {
        if (isPrime[i]) primes.insert(i);
        for (int p : primes) 
        {
            if (1LL * i * p > n) break; 
            isPrime[i * p] = false; 
            if (i % p == 0) break; 
        }
    }

    set<int> ans;

    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        int flag2 = 0;
        while (x)
        {
            if (x == 1) break;
            if (primes.count(x))
            {
                if (!ans.count(x)) ans.insert(x);       
                break;
            }
            if (isprime(x)) 
            {
                if (!ans.count(x)) ans.insert(x);
                break;
            }
            for (int p : primes)
            {
                if (x % p == 0) 
                {
                    if (!ans.count(p))
                    {
                        ans.insert(p);
                        flag2 = 1;
                        break;
                    }
                    while (x % p == 0) 
                    {
                        x /= p;
                        if (x < p) break;
                    }
                    if (x < p) break;
                }
            }
            if (flag2) break;
        }
    }

    int flag1 = 1;
    for (int x : ans)
    {
        for (int i = 1;;i++)
        {
            if (1LL * i * x > k) break;
            if (!cnt.count(x * i))
            {
                flag1 = 0;
                break;
            }
        }
        if (flag1 == 0) break;
    }
    if (flag1 == 0) cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

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