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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int l = 0,r = n - 1;
    long long ans = 0;

    while (l < r && a[l] >= 0) 
    {
        ans += a[l];
        l++;
    }
    while (l < r && a[r] < 0)
    {
        ans -= a[r];
        r--;
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