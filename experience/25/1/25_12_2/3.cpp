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
    int a,b;
    cin >> a >> b;
    int ans = 0;
    if (a <= b)
    {
        int d = b - a;
        if (d == 0) ans = 0;
        else if (d & 1) ans = 1;
        else ans = 2;
    }
    else 
    {
        int d = a - b;
        if (d & 1) ans = 2;
        else ans = 1;
    }
    cout << ans << endl;
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