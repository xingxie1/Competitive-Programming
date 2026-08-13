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
    if (n == 1) cout << 1 << endl;
    else if (n == 2) cout << 9 << endl;
    else if (n == 3) cout << 29 << endl;
    else if (n == 4) cout << 56 << endl;
    else 
    {
        long long ans = n * n - n - 1;
        ans *= 5;
        cout << ans << endl;
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