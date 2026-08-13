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
    for (int i = 2;i <= sqrt(a);i++)
    {
        if (a % i == 0)return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    if (isprime(n))
    {
        cout << 1 << " " << n - 1 << endl;
        return ;
    }
    int a = 1,b = n - 1;
    vector<long long> res;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(),res.end());
    for (int i : res)
    {
        if (n % i == 0)
        {
            int na = i,nb = n - na;
            if (lcm(na,nb) < lcm(a,b))
            {
                a = na;
                b = nb;
            }
        }
    }
    cout << a << " " << b << endl;
    
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