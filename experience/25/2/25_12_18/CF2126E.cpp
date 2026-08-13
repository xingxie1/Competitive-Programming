// https://codeforces.com/problemset/problem/2126/E
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt p(n),s(n);
    for (int i = 0;i < n;i++) cin >> p[i];
    for (int i = 0;i < n;i++) cin >> s[i];

    if (p[n - 1] != s[0])
    {
        cout << "No" << endl;
        return ;
    }
    for (int i = 0;i < n;i++)
    {
        int flag1 = 0,flag2 = 0;
        if (i)
        {
            if (gcd(p[i - 1] / p[i],s[i]) != 1)
            {
                flag1 = 1;
            }
        }
        if (i < n - 1)
        {
            if (gcd(s[i + 1] / s[i],p[i]) != 1)
            {
                flag2 = 1;
            }
        }
        if (flag1 && flag2)
        {
            cout << "NO" << endl;
            return ;
        }
    }
    cout << "YES" << endl;
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