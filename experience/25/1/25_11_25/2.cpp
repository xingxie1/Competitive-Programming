#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(2 * n);
    int t = n;
    a[0] = a[n] = n;
    t = 1;
    for (int i = 1;i < n;i++)
    {
        a[n + i] = a[n - i] = t++;
    }

    for (int i = 0;i < 2 * n;i++) cout << a[i] << " ";
    cout << endl;
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