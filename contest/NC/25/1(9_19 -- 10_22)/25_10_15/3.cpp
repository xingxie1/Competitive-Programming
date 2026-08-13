#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int isprime(long long a)
{
    if (a == 1) return 0;
    if (a == 2) return 1;
    for (int i = 2;i <= sqrt(a);i++)
    {
        if (a % i == 0) return 0;
    }
    return 1;
}

int f(long long a)
{
    if (isprime(a)) return 2;
    map<int,int> cnt;
    while (a > 1)
    {
        for (int i = 2;i <= a;i++)
        {
            if (a % i == 0)
            {
                cnt[i]++;
                a /= i;
                break;
            }
        }
    }
    auto it = cnt.begin();
    int ans = 1;
    while (it != cnt.end())
    {
        ans *= (it->second + 1);
        it++;
    }
    return ans;
    
}

void solve()
{
    long long n;
    cin >> n;
    int cnt = 0;
    while (n != 2)
    {
        int x = f(n);
        n = x;
        cnt++;
    }
    cout << cnt ;
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