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
    int n,x;
    cin >> n >> x;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    long long ans = 0;
    long long sum = 0;
    vt aa;
    int l = 0,r = n - 1;
    while (l <= r)
    {
        if ((sum + a[r]) / x > sum / x)
        {
            ans += a[r];
            sum += a[r];
            aa.push_back(a[r]);
            r--;
        }   
        else 
        {
            sum += a[l];
            aa.push_back(a[l]);
            l++;
        }
    }

    cout << ans << endl;
    for (int i = 0;i < n;i++) cout << aa[i] << " ";
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